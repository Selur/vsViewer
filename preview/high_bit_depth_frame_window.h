#ifndef HIGH_BIT_DEPTH_FRAME_WINDOW_H
#define HIGH_BIT_DEPTH_FRAME_WINDOW_H

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWindow>
#include <memory>

class QRhi;
class QRhiBuffer;
class QRhiGraphicsPipeline;
class QRhiRenderPassDescriptor;
class QRhiSampler;
class QRhiShaderResourceBindings;
class QRhiSwapChain;
class QRhiTexture;

// Shows the preview frame through a Direct3D 11 swapchain, 16 bit float scRGB when HDR is wanted and the display offers it, else SDR; the GPU scales it to the display size.
class HighBitDepthFrameWindow : public QWindow
{
    Q_OBJECT

  public:
    explicit HighBitDepthFrameWindow(bool a_hdr, QWindow* a_pParent = nullptr);

    ~HighBitDepthFrameWindow() override;

    // a_displaySize: device pixels the frame covers (empty: 1 image pixel per device pixel); a_smooth: linear instead of nearest sampling
    void setFrame(const QImage& a_image, const QSize& a_displaySize = QSize(), bool a_smooth = false);

    void setFrameOffset(const QPoint& a_deviceOffset);

    void setBackground(const QColor& a_color);

  signals:

    void signalStatus(bool a_isError, const QString& a_message);
    // no Direct3D device, swapchain or pipeline: the owner falls back to drawing the frames itself
    void signalInitFailed();

  protected:
    void exposeEvent(QExposeEvent* a_pEvent) override;
    bool event(QEvent* a_pEvent) override;

  private:
    bool initialize();
    void releaseResources();
    bool ensureTexture();
    bool createBindings();
    void render();

    std::unique_ptr<QRhi> m_rhi;
    std::unique_ptr<QRhiSwapChain> m_swapChain;
    std::unique_ptr<QRhiRenderPassDescriptor> m_renderPass;
    std::unique_ptr<QRhiBuffer> m_uniformBuffer;
    std::unique_ptr<QRhiSampler> m_samplerNearest;
    std::unique_ptr<QRhiSampler> m_samplerLinear;
    std::unique_ptr<QRhiTexture> m_texture;
    std::unique_ptr<QRhiShaderResourceBindings> m_bindingsNearest;
    std::unique_ptr<QRhiShaderResourceBindings> m_bindingsLinear;
    std::unique_ptr<QRhiGraphicsPipeline> m_pipeline;

    bool m_initialized = false;
    bool m_initFailed = false;
    bool m_hdrWanted = false;
    bool m_hdrSwapChain = false;
    QSize m_swapChainSize;

    QImage m_image;
    QSize m_displaySize;
    bool m_smooth = false;
    bool m_imageDirty = false;
    bool m_swizzleBgr = false;
    QPoint m_offset;
    QColor m_background = Qt::black;
};

#endif  // HIGH_BIT_DEPTH_FRAME_WINDOW_H
