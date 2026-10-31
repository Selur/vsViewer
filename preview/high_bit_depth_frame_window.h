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

// Shows the preview frame through a 16 bit float scRGB Direct3D 11 swapchain, 1 image pixel per device pixel.
class HighBitDepthFrameWindow : public QWindow
{
    Q_OBJECT

  public:
    explicit HighBitDepthFrameWindow(QWindow* a_pParent = nullptr);

    ~HighBitDepthFrameWindow() override;

    void setFrame(const QImage& a_image);

    void setFrameOffset(const QPoint& a_deviceOffset);

    void setBackground(const QColor& a_color);

  signals:

    void signalStatus(bool a_isError, const QString& a_message);

  protected:
    void exposeEvent(QExposeEvent* a_pEvent) override;
    bool event(QEvent* a_pEvent) override;

  private:
    bool initialize();
    void releaseResources();
    bool ensureTexture();
    void render();

    std::unique_ptr<QRhi> m_rhi;
    std::unique_ptr<QRhiSwapChain> m_swapChain;
    std::unique_ptr<QRhiRenderPassDescriptor> m_renderPass;
    std::unique_ptr<QRhiBuffer> m_uniformBuffer;
    std::unique_ptr<QRhiSampler> m_sampler;
    std::unique_ptr<QRhiTexture> m_texture;
    std::unique_ptr<QRhiShaderResourceBindings> m_bindings;
    std::unique_ptr<QRhiGraphicsPipeline> m_pipeline;

    bool m_initialized = false;
    bool m_initFailed = false;
    bool m_hdrSwapChain = false;
    QSize m_swapChainSize;

    QImage m_image;
    bool m_imageDirty = false;
    bool m_swizzleBgr = false;
    QPoint m_offset;
    QColor m_background = Qt::black;
};

#endif  // HIGH_BIT_DEPTH_FRAME_WINDOW_H
