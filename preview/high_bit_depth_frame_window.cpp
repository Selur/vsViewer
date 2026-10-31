#include "high_bit_depth_frame_window.h"

#include <QEvent>
#include <QExposeEvent>
#include <QPlatformSurfaceEvent>
#include <rhi/qrhi.h>

//==============================================================================

namespace
{
// Full-window triangle; the pixel shader places the frame at the offset, scaled to the display size by the sampler, and linearises sRGB for scRGB output.
const char HLSL_SOURCE[] = R"(
cbuffer Params : register(b0)
{
  float4 offsetSize;
  float4 background;
  float4 options;
};

Texture2D<float4> frameTexture : register(t1);
SamplerState frameSampler : register(s1);

struct VsOut
{
  float4 position : SV_Position;
};

VsOut vsMain(uint id : SV_VertexID)
{
  VsOut output;
  float2 uv = float2((id << 1) & 2, id & 2);
  output.position = float4(uv * float2(2.0, -2.0) + float2(-1.0, 1.0), 0.0, 1.0);
  return output;
}

float3 srgbToLinear(float3 c)
{
  float3 low = c / 12.92;
  float3 high = pow((c + 0.055) / 1.055, 2.4);
  return float3(c.r <= 0.04045 ? low.r : high.r,
                c.g <= 0.04045 ? low.g : high.g,
                c.b <= 0.04045 ? low.b : high.b);
}

float4 psMain(VsOut input) : SV_Target
{
  float2 p = input.position.xy - offsetSize.xy;
  float3 color = background.rgb;
  if (p.x >= 0.0 && p.y >= 0.0 && p.x < offsetSize.z && p.y < offsetSize.w) {
    float4 texel = frameTexture.Sample(frameSampler, p / offsetSize.zw);
    color = options.y > 0.5 ? texel.bgr : texel.rgb;
  }
  if (options.z > 0.5) color = srgbToLinear(color) * options.x;
  return float4(color, 1.0);
}
)";

QShader hlslShader(QShader::Stage a_stage, const char* a_entryPoint)
{
  QShader shader;
  shader.setStage(a_stage);
  shader.setShader(QShaderKey(QShader::HlslShader, QShaderVersion(50)), QShaderCode(QByteArray(HLSL_SOURCE), QByteArray(a_entryPoint)));
  return shader;
}

struct UniformData
{
  float offsetSize[4];
  float background[4];
  float options[4];
};
}  // namespace

//==============================================================================

HighBitDepthFrameWindow::HighBitDepthFrameWindow(bool a_hdr, QWindow* a_pParent) : QWindow(a_pParent), m_hdrWanted(a_hdr)
{
  setSurfaceType(QSurface::Direct3DSurface);
  setFlag(Qt::WindowTransparentForInput, true);
}

// END OF HighBitDepthFrameWindow::HighBitDepthFrameWindow(QWindow * a_pParent)
//==============================================================================

HighBitDepthFrameWindow::~HighBitDepthFrameWindow() { releaseResources(); }

// END OF HighBitDepthFrameWindow::~HighBitDepthFrameWindow()
//==============================================================================

void HighBitDepthFrameWindow::setFrame(const QImage& a_image, const QSize& a_displaySize, bool a_smooth)
{
  m_image = a_image;
  m_displaySize = a_displaySize.isEmpty() ? a_image.size() : a_displaySize;
  m_smooth = a_smooth;
  m_imageDirty = true;
  requestUpdate();
}

// END OF void HighBitDepthFrameWindow::setFrame(const QImage & a_image)
//==============================================================================

void HighBitDepthFrameWindow::setFrameOffset(const QPoint& a_deviceOffset)
{
  if (m_offset == a_deviceOffset) return;
  m_offset = a_deviceOffset;
  requestUpdate();
}

// END OF void HighBitDepthFrameWindow::setFrameOffset(const QPoint & a_deviceOffset)
//==============================================================================

void HighBitDepthFrameWindow::setBackground(const QColor& a_color)
{
  m_background = a_color;
  requestUpdate();
}

// END OF void HighBitDepthFrameWindow::setBackground(const QColor & a_color)
//==============================================================================

void HighBitDepthFrameWindow::exposeEvent(QExposeEvent* a_pEvent)
{
  Q_UNUSED(a_pEvent);
  if (!isExposed()) return;
  if (!m_initialized && !m_initFailed) initialize();
  render();
}

// END OF void HighBitDepthFrameWindow::exposeEvent(QExposeEvent * a_pEvent)
//==============================================================================

bool HighBitDepthFrameWindow::event(QEvent* a_pEvent)
{
  if (a_pEvent->type() == QEvent::UpdateRequest) {
    render();
  }
  else if (a_pEvent->type() == QEvent::PlatformSurface) {
    if (static_cast<QPlatformSurfaceEvent*>(a_pEvent)->surfaceEventType() == QPlatformSurfaceEvent::SurfaceAboutToBeDestroyed) releaseResources();
  }
  return QWindow::event(a_pEvent);
}

// END OF bool HighBitDepthFrameWindow::event(QEvent * a_pEvent)
//==============================================================================

bool HighBitDepthFrameWindow::initialize()
{
  QRhiD3D11InitParams params;
  m_rhi.reset(QRhi::create(QRhi::D3D11, &params));
  if (!m_rhi) {
    m_initFailed = true;
    emit signalStatus(true, tr("GPU preview: could not create a Direct3D 11 device, the frames are drawn by the CPU."));
    emit signalInitFailed();
    return false;
  }

  m_swapChain.reset(m_rhi->newSwapChain());
  m_swapChain->setWindow(this);
  m_hdrSwapChain = m_hdrWanted && m_swapChain->isFormatSupported(QRhiSwapChain::HDRExtendedSrgbLinear);
  if (m_hdrSwapChain) m_swapChain->setFormat(QRhiSwapChain::HDRExtendedSrgbLinear);
  m_renderPass.reset(m_swapChain->newCompatibleRenderPassDescriptor());
  m_swapChain->setRenderPassDescriptor(m_renderPass.get());
  if (!m_swapChain->createOrResize()) {
    m_initFailed = true;
    emit signalStatus(true, tr("GPU preview: could not create the swapchain, the frames are drawn by the CPU."));
    emit signalInitFailed();
    return false;
  }
  m_swapChainSize = m_swapChain->currentPixelSize();

  m_uniformBuffer.reset(m_rhi->newBuffer(QRhiBuffer::Dynamic, QRhiBuffer::UniformBuffer, sizeof(UniformData)));
  m_uniformBuffer->create();
  m_samplerNearest.reset(m_rhi->newSampler(QRhiSampler::Nearest, QRhiSampler::Nearest, QRhiSampler::None, QRhiSampler::ClampToEdge, QRhiSampler::ClampToEdge));
  m_samplerNearest->create();
  m_samplerLinear.reset(m_rhi->newSampler(QRhiSampler::Linear, QRhiSampler::Linear, QRhiSampler::None, QRhiSampler::ClampToEdge, QRhiSampler::ClampToEdge));
  m_samplerLinear->create();
  m_texture.reset(m_rhi->newTexture(QRhiTexture::RGBA8, QSize(1, 1)));
  m_texture->create();
  if (!createBindings()) {
    m_initFailed = true;
    emit signalStatus(true, tr("GPU preview: could not bind the frame texture, the frames are drawn by the CPU."));
    emit signalInitFailed();
    return false;
  }

  m_pipeline.reset(m_rhi->newGraphicsPipeline());
  m_pipeline->setShaderStages({{QRhiShaderStage::Vertex, hlslShader(QShader::VertexStage, "vsMain")},
                               {QRhiShaderStage::Fragment, hlslShader(QShader::FragmentStage, "psMain")}});
  m_pipeline->setVertexInputLayout(QRhiVertexInputLayout());
  m_pipeline->setShaderResourceBindings(m_bindingsNearest.get());
  m_pipeline->setRenderPassDescriptor(m_renderPass.get());
  if (!m_pipeline->create()) {
    m_initFailed = true;
    emit signalStatus(true, tr("GPU preview: could not build the shader pipeline, the frames are drawn by the CPU."));
    emit signalInitFailed();
    return false;
  }

  m_initialized = true;
  if (m_hdrSwapChain) {
    QRhiSwapChainHdrInfo hdrInfo = m_swapChain->hdrInfo();
    emit signalStatus(false, tr("10 bit preview: scRGB swapchain active, SDR white %1 nits.").arg(hdrInfo.sdrWhiteLevel));
  }
  else if (m_hdrWanted) {
    emit signalStatus(true, tr("10 bit preview: the display offers no HDR swapchain (Windows HDR off), output stays 8 bit."));
  }
  else {
    emit signalStatus(false, tr("GPU preview: SDR swapchain active, frames scaled on the GPU."));
  }
  return true;
}

// END OF bool HighBitDepthFrameWindow::initialize()
//==============================================================================

// One binding set per sampler, both on the current texture; the pipeline layout is the same for both.
bool HighBitDepthFrameWindow::createBindings()
{
  QRhiSampler* samplers[] = {m_samplerNearest.get(), m_samplerLinear.get()};
  std::unique_ptr<QRhiShaderResourceBindings>* bindings[] = {&m_bindingsNearest, &m_bindingsLinear};
  for (int i = 0; i < 2; ++i) {
    bindings[i]->reset(m_rhi->newShaderResourceBindings());
    (*bindings[i])->setBindings({QRhiShaderResourceBinding::uniformBuffer(0, QRhiShaderResourceBinding::FragmentStage, m_uniformBuffer.get()),
                                 QRhiShaderResourceBinding::sampledTexture(1, QRhiShaderResourceBinding::FragmentStage, m_texture.get(), samplers[i])});
    if (!(*bindings[i])->create()) return false;
  }
  return true;
}

// END OF bool HighBitDepthFrameWindow::createBindings()
//==============================================================================

void HighBitDepthFrameWindow::releaseResources()
{
  m_pipeline.reset();
  m_bindingsNearest.reset();
  m_bindingsLinear.reset();
  m_texture.reset();
  m_samplerNearest.reset();
  m_samplerLinear.reset();
  m_uniformBuffer.reset();
  m_renderPass.reset();
  m_swapChain.reset();
  m_rhi.reset();
  m_initialized = false;
  m_imageDirty = !m_image.isNull();
}

// END OF void HighBitDepthFrameWindow::releaseResources()
//==============================================================================

bool HighBitDepthFrameWindow::ensureTexture()
{
  if (!m_imageDirty) return false;
  if (m_image.isNull()) return false;

  QRhiTexture::Format format = QRhiTexture::RGBA8;
  m_swizzleBgr = false;
  if (m_image.format() == QImage::Format_RGB30 || m_image.format() == QImage::Format_A2RGB30_Premultiplied) {
    format = QRhiTexture::RGB10A2;
    m_swizzleBgr = true;
  }
  else if (m_image.format() == QImage::Format_BGR30 || m_image.format() == QImage::Format_A2BGR30_Premultiplied) {
    format = QRhiTexture::RGB10A2;
  }
  else if (m_image.format() == QImage::Format_ARGB32 || m_image.format() == QImage::Format_RGB32
           || m_image.format() == QImage::Format_ARGB32_Premultiplied) {
    // Qt's 32 bit formats are BGRA bytes in memory: uploaded as such, no conversion of the 8 bit frames
    format = QRhiTexture::BGRA8;
  }
  else if (m_image.format() != QImage::Format_RGBA8888) {
    m_image = m_image.convertToFormat(QImage::Format_RGBA8888);
  }

  if (m_texture->format() != format || m_texture->pixelSize() != m_image.size()) {
    if (m_texture->format() != format)
      emit signalStatus(false, format == QRhiTexture::RGB10A2 ? tr("10 bit preview: frames arrive with 10 bit per channel.")
                                                              : tr("10 bit preview: frames arrive with 8 bit per channel."));
    m_texture.reset(m_rhi->newTexture(format, m_image.size()));
    if (!m_texture->create()) return false;
    if (!createBindings()) return false;
  }
  return true;
}

// END OF bool HighBitDepthFrameWindow::ensureTexture()
//==============================================================================

void HighBitDepthFrameWindow::render()
{
  if (!m_initialized || !isExposed()) return;

  if (m_swapChain->currentPixelSize() != m_swapChain->surfacePixelSize()) {
    if (!m_swapChain->createOrResize()) return;
    m_swapChainSize = m_swapChain->currentPixelSize();
  }
  if (m_swapChainSize.isEmpty()) return;

  QRhi::FrameOpResult result = m_rhi->beginFrame(m_swapChain.get());
  if (result == QRhi::FrameOpSwapChainOutOfDate) {
    if (!m_swapChain->createOrResize()) return;
    m_swapChainSize = m_swapChain->currentPixelSize();
    result = m_rhi->beginFrame(m_swapChain.get());
  }
  if (result != QRhi::FrameOpSuccess) return;

  QRhiResourceUpdateBatch* pUpdates = m_rhi->nextResourceUpdateBatch();
  if (ensureTexture()) {
    QRhiTextureSubresourceUploadDescription subresource(m_image.constBits(), int(m_image.sizeInBytes()));
    subresource.setDataStride(quint32(m_image.bytesPerLine()));
    pUpdates->uploadTexture(m_texture.get(), QRhiTextureUploadDescription({0, 0, subresource}));
  }
  m_imageDirty = false;

  float whiteScale = 1.0f;
  if (m_hdrSwapChain) {
    QRhiSwapChainHdrInfo hdrInfo = m_swapChain->hdrInfo();
    if (hdrInfo.sdrWhiteLevel > 0.0f) whiteScale = hdrInfo.sdrWhiteLevel / 80.0f;
  }
  const QSize frameSize = m_image.isNull() ? QSize(0, 0) : m_displaySize;
  UniformData uniforms = {{float(m_offset.x()), float(m_offset.y()), float(frameSize.width()), float(frameSize.height())},
                          {float(m_background.redF()), float(m_background.greenF()), float(m_background.blueF()), 1.0f},
                          {whiteScale, m_swizzleBgr ? 1.0f : 0.0f, m_hdrSwapChain ? 1.0f : 0.0f, 0.0f}};
  pUpdates->updateDynamicBuffer(m_uniformBuffer.get(), 0, sizeof(UniformData), &uniforms);

  QRhiCommandBuffer* pCommands = m_swapChain->currentFrameCommandBuffer();
  QRhiRenderTarget* pTarget = m_swapChain->currentFrameRenderTarget();
  pCommands->beginPass(pTarget, Qt::black, {1.0f, 0}, pUpdates);
  pCommands->setGraphicsPipeline(m_pipeline.get());
  pCommands->setViewport(QRhiViewport(0, 0, m_swapChainSize.width(), m_swapChainSize.height()));
  pCommands->setShaderResources(m_smooth ? m_bindingsLinear.get() : m_bindingsNearest.get());
  pCommands->draw(3);
  pCommands->endPass();
  m_rhi->endFrame(m_swapChain.get());
}

// END OF void HighBitDepthFrameWindow::render()
//==============================================================================
