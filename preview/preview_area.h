#ifndef PREVIEWAREA_H
#define PREVIEWAREA_H

#include <QImage>
#include <QPixmap>
#include <QPoint>
#include <QScrollArea>

class QLabel;
class ScrollNavigator;
class HighBitDepthFrameWindow;
class QKeyEvent;
class QWheelEvent;
class QMouseEvent;
class QEnterEvent;

class PreviewArea : public QScrollArea
{
    Q_OBJECT

  public:
    PreviewArea(QWidget* a_pParent = nullptr);

    virtual ~PreviewArea();

    void setWidget(QWidget* a_pWidget) = delete;

    int pixmapWidth() const { return m_pixmapWidth; }

    int pixmapHeight() const { return m_pixmapHeight; }

    // a plain picture shown as it is (blank, black)
    void setPixmap(const QPixmap& a_pixmap);

    // the unscaled frame (ARGB32 or RGB30) shown at a_displaySize device pixels: scaled on the GPU where the Direct3D window runs, else by the CPU with a_mode
    void setFrame(const QImage& a_frame, const QSize& a_displaySize, bool a_isVideoFrame, Qt::TransformationMode a_mode);

    bool gpuDisplay() const { return m_pHighBitDepthWindow != nullptr; }

    bool highBitDepthOutput() const { return m_gpuHdr && m_pHighBitDepthWindow != nullptr; }

    void checkMouseOverPreview(const QPointF& a_pixelPos);

    QPointF pixelPosition() const;

    QPoint getScrollBarPositions() const;

    void getScrollBarPositionsFromPreviewer(const QPoint& pos);

    // the Direct3D window shows every frame; a_hdr asks for the scRGB swapchain of the 10 bit output
    void setGpuDisplay(bool a_hdr);

  public slots:
    void slotGpuDisplayFailed();

    void slotScrollLeft();
    void slotScrollRight();
    void slotScrollTop();
    void slotScrollBottom();
    void slotSetScrollBarPositions();

  protected:
    void resizeEvent(QResizeEvent* a_pEvent) override;
    void keyPressEvent(QKeyEvent* a_pEvent) override;
    void wheelEvent(QWheelEvent* a_pEvent) override;
    void mousePressEvent(QMouseEvent* a_pEvent) override;
    void mouseMoveEvent(QMouseEvent* a_pEvent) override;
    void mouseReleaseEvent(QMouseEvent* a_pEvent) override;
    void enterEvent(QEnterEvent* a_pEvent) override;

  signals:

    void signalSizeChanged();
    void signalCtrlWheel(QPoint a_angleDelta);
    void signalMouseMiddleButtonReleased();
    void signalMouseRightButtonReleased();
    void signalMouseOverPoint(double a_normX, double a_normY);
    void signalHighBitDepthStatus(bool a_isError, const QString& a_message);
    // the Direct3D window could not start: the owner sends the frame again for the CPU path
    void signalGpuDisplayLost();

  protected:
    bool eventFilter(QObject* a_pObject, QEvent* a_pEvent) override;

  private:
    void drawScrollNavigator();
    void updateHighBitDepthView();

    QLabel* m_pPreviewLabel;

    ScrollNavigator* m_pScrollNavigator;

    bool m_draggingPreview;
    QPoint m_lastCursorPos;
    QPoint m_lastPreviewLabelPos;
    QPointF m_lastScenePos;

    int m_pixmapWidth = 0;
    int m_pixmapHeight = 0;

    bool m_newToPreviewer;
    QPoint m_lastScrollBarPos;

    HighBitDepthFrameWindow* m_pHighBitDepthWindow = nullptr;
    QWidget* m_pHighBitDepthContainer = nullptr;
    bool m_gpuHdr = false;
    // the label's pixmap under the Direct3D window: only its size matters, for scrolling and mouse mapping
    QPixmap m_placeholder;
};

#endif  // PREVIEWAREA_H
