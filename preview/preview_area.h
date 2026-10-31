#ifndef PREVIEWAREA_H
#define PREVIEWAREA_H

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

    // a_highBitDepthImage: the same picture as RGB30 for the 10 bit view; empty falls back to the pixmap
    void setPixmap(const QPixmap& a_pixmap, bool a_isVideoFrame = false, const QImage& a_highBitDepthImage = QImage());

    bool highBitDepthOutput() const { return m_pHighBitDepthWindow != nullptr; }

    void checkMouseOverPreview(const QPointF& a_pixelPos);

    QPointF pixelPosition() const;

    QPoint getScrollBarPositions() const;

    void getScrollBarPositionsFromPreviewer(const QPoint& pos);

    void setHighBitDepthOutput(bool a_enabled);

  public slots:

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
};

#endif  // PREVIEWAREA_H
