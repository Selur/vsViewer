#include "preview_area.h"

#include "scroll_navigator.h"
#ifdef Q_OS_WIN
#include "high_bit_depth_frame_window.h"
#endif

#include <QCoreApplication>
#include <QEnterEvent>
#include <QKeyEvent>
#include <QLabel>
#include <QMouseEvent>
#include <QScrollBar>
#include <QTimer>
#include <QWheelEvent>

//==============================================================================

PreviewArea::PreviewArea(QWidget *a_pParent)
  : QScrollArea(a_pParent), m_pPreviewLabel(nullptr), m_pScrollNavigator(nullptr), m_draggingPreview(false), m_lastCursorPos(0, 0),
    m_lastPreviewLabelPos(0, 0), m_lastScenePos(0.0, 0.0), m_newToPreviewer(false)
{
  m_pPreviewLabel = new QLabel(this);
  m_pPreviewLabel->setPixmap(QPixmap());
  m_pPreviewLabel->setAlignment(Qt::AlignTop | Qt::AlignLeft);
  m_pPreviewLabel->move(0, 0);
  QScrollArea::setWidget(m_pPreviewLabel);
  setWidgetResizable(true);

  m_pScrollNavigator = new ScrollNavigator(this);
  int scrollFrameWidth = frameWidth();
  m_pScrollNavigator->move(pos() + QPoint(scrollFrameWidth, scrollFrameWidth));
  m_pScrollNavigator->setVisible(false);

  setAttribute(Qt::WA_Hover, true);
  setMouseTracking(true);
  m_pPreviewLabel->setMouseTracking(true);

  m_pPreviewLabel->installEventFilter(this);
  viewport()->installEventFilter(this);
}

// END OF PreviewArea::PreviewArea(QWidget * a_pParent)
//==============================================================================

PreviewArea::~PreviewArea() {}

// END OF PreviewArea::~PreviewArea()
//==============================================================================

void PreviewArea::setPixmap(const QPixmap &a_pixmap, bool a_isVideoFrame, const QImage &a_highBitDepthImage)
{
  m_pPreviewLabel->setPixmap(a_pixmap);
  m_pixmapWidth = a_pixmap.width();
  m_pixmapHeight = a_pixmap.height();
#ifdef Q_OS_WIN
  if (m_pHighBitDepthWindow) {
    m_pHighBitDepthWindow->setFrame(a_highBitDepthImage.isNull() ? a_pixmap.toImage() : a_highBitDepthImage);
    updateHighBitDepthView();
  }
#endif
  if (a_isVideoFrame && m_newToPreviewer) {
    m_newToPreviewer = false;
    QCoreApplication::processEvents();
    QTimer::singleShot(0, this, SLOT(slotSetScrollBarPositions()));
  }
}

// END OF void PreviewArea::setPixmap(const QPixmap & a_pixmap)
//==============================================================================

void PreviewArea::checkMouseOverPreview(const QPointF &a_pixelPos)
{
  if (!m_pPreviewLabel->underMouse()) return;

  double pX = a_pixelPos.x();
  double pY = a_pixelPos.y();
  if (pX < 0 || pY < 0 || pX >= pixmapWidth() || pY >= pixmapHeight()) return;

  emit signalMouseOverPoint(pX, pY);
}

// END OF void PreviewArea::checkMouseOverPreview(
//		const QPoint & a_globalMousePos)
//==============================================================================

void PreviewArea::slotScrollLeft() { horizontalScrollBar()->setValue(0); }

// END OF void PreviewArea::slotScrollLeft()
//==============================================================================

void PreviewArea::slotScrollRight()
{
  QCoreApplication::processEvents();
  QScrollBar *pHorizontalScrollbar = horizontalScrollBar();
  pHorizontalScrollbar->setValue(pHorizontalScrollbar->maximum());
}

// END OF void PreviewArea::slotScrollRight()
//==============================================================================

void PreviewArea::slotScrollTop() { verticalScrollBar()->setValue(0); }

// END OF void PreviewArea::slotScrollTop()
//==============================================================================

void PreviewArea::slotScrollBottom()
{
  QCoreApplication::processEvents();
  QScrollBar *pVerticalScrollbar = verticalScrollBar();
  pVerticalScrollbar->setValue(pVerticalScrollbar->maximum());
}

// END OF void PreviewArea::slotScrollBottom()
//==============================================================================

void PreviewArea::resizeEvent(QResizeEvent *a_pEvent)
{
  QScrollArea::resizeEvent(a_pEvent);
  emit signalSizeChanged();
}

// END OF void PreviewArea::resizeEvent(QResizeEvent * a_pEvent)
//==============================================================================

void PreviewArea::keyPressEvent(QKeyEvent *a_pEvent)
{
  if (a_pEvent->modifiers() != Qt::NoModifier) {
    QScrollArea::keyPressEvent(a_pEvent);
    return;
  }

  int key = a_pEvent->key();
  int wantedKeys[] = {Qt::Key_Left, Qt::Key_Right, Qt::Key_Up, Qt::Key_Down, Qt::Key_PageUp, Qt::Key_PageDown, Qt::Key_Home, Qt::Key_End};
  int *pKeysEnd = wantedKeys + sizeof(wantedKeys) / sizeof(*wantedKeys);
  if (pKeysEnd != std::find(wantedKeys, pKeysEnd, key)) {
    a_pEvent->ignore();
    return;
  }

  QScrollArea::keyPressEvent(a_pEvent);
}

// END OF void PreviewArea::keyPressEvent(QKeyEvent * a_pEvent)
//==============================================================================

void PreviewArea::wheelEvent(QWheelEvent *a_pEvent)
{
  if (a_pEvent->modifiers() == Qt::ControlModifier) {
    emit signalCtrlWheel(a_pEvent->angleDelta());
    a_pEvent->ignore();
    return;
  }

  QScrollArea::wheelEvent(a_pEvent);
}

// END OF void PreviewArea::wheelEvent(QWheelEvent * a_pEvent)
//==============================================================================

void PreviewArea::mousePressEvent(QMouseEvent *a_pEvent)
{
  if (a_pEvent->buttons() == Qt::LeftButton) {
    m_draggingPreview = true;
    m_lastCursorPos = a_pEvent->globalPosition().toPoint();
    m_lastPreviewLabelPos = m_pPreviewLabel->pos();
    m_pScrollNavigator->setVisible(true);
    drawScrollNavigator();
    a_pEvent->accept();
    return;
  }

  QScrollArea::mousePressEvent(a_pEvent);
}

// END OF void PreviewArea::mousePressEvent(QMouseEvent * a_pEvent)
//==============================================================================

void PreviewArea::mouseMoveEvent(QMouseEvent *a_pEvent)
{
  if ((a_pEvent->buttons() & Qt::LeftButton) && m_draggingPreview) {
    QPoint newCursorPos = a_pEvent->globalPosition().toPoint();
    QPoint posDifference = newCursorPos - m_lastCursorPos;
    QPoint newPreviewLabelPos = m_lastPreviewLabelPos + posDifference;

    horizontalScrollBar()->setValue(-newPreviewLabelPos.x());
    verticalScrollBar()->setValue(-newPreviewLabelPos.y());

    drawScrollNavigator();
    a_pEvent->accept();
    return;
  }
  m_lastScenePos = a_pEvent->scenePosition();
  checkMouseOverPreview(pixelPosition());

  QScrollArea::mouseMoveEvent(a_pEvent);
}

// END OF void PreviewArea::mouseMoveEvent(QMouseEvent * a_pEvent)
//==============================================================================

void PreviewArea::mouseReleaseEvent(QMouseEvent *a_pEvent)
{
  Qt::MouseButton releasedButton = a_pEvent->button();
  if (releasedButton == Qt::LeftButton) {
    m_draggingPreview = false;
    m_pScrollNavigator->setVisible(false);
    a_pEvent->accept();
    return;
  }
  else if (releasedButton == Qt::MiddleButton)
    emit signalMouseMiddleButtonReleased();
  else if (releasedButton == Qt::RightButton)
    emit signalMouseRightButtonReleased();

  QScrollArea::mouseReleaseEvent(a_pEvent);
}

void PreviewArea::enterEvent(QEnterEvent *a_pEvent)
{
  m_lastScenePos = a_pEvent->scenePosition();
  checkMouseOverPreview(pixelPosition());
  QScrollArea::enterEvent(a_pEvent);
  setAttribute(Qt::WA_Hover, false);
}

// END OF void PreviewArea::mouseReleaseEvent(QMouseEvent * a_pEvent)
//==============================================================================

void PreviewArea::drawScrollNavigator()
{
  int contentsWidth = this->pixmapWidth();
  int contentsHeight = this->pixmapHeight();
  int viewportX = -m_pPreviewLabel->x();
  int viewportY = -m_pPreviewLabel->y();
  int viewportWidth = viewport()->width();
  int viewportHeight = viewport()->height();

  m_pScrollNavigator->draw(contentsWidth, contentsHeight, viewportX, viewportY, viewportWidth, viewportHeight);
}

// END OF void PreviewArea::drawScrollNavigator()
//==============================================================================

QPointF PreviewArea::pixelPosition() const
{
  QPoint lPos = m_pPreviewLabel->geometry().topLeft();
  QMargins lMargin = contentsMargins();
  QPoint mOffset = QPoint(lMargin.left(), lMargin.top());
  return m_lastScenePos - lPos - mOffset;
}

QPoint PreviewArea::getScrollBarPositions() const
{
  int x = horizontalScrollBar()->value();
  int y = verticalScrollBar()->value();
  return QPoint(x, y);
}

void PreviewArea::slotSetScrollBarPositions()
{
  horizontalScrollBar()->setValue(m_lastScrollBarPos.x());
  verticalScrollBar()->setValue(m_lastScrollBarPos.y());
}

void PreviewArea::getScrollBarPositionsFromPreviewer(const QPoint &pos)
{
  m_newToPreviewer = true;
  m_lastScrollBarPos = pos;
}

void PreviewArea::setHighBitDepthOutput(bool a_enabled)
{
#ifdef Q_OS_WIN
  if (a_enabled == (m_pHighBitDepthWindow != nullptr)) return;

  if (!a_enabled) {
    delete m_pHighBitDepthContainer;
    m_pHighBitDepthContainer = nullptr;
    m_pHighBitDepthWindow = nullptr;
    return;
  }

  m_pHighBitDepthWindow = new HighBitDepthFrameWindow();
  connect(m_pHighBitDepthWindow, &HighBitDepthFrameWindow::signalStatus, this, &PreviewArea::signalHighBitDepthStatus);
  // the container takes ownership of the window; mouse input falls through to the viewport
  m_pHighBitDepthContainer = QWidget::createWindowContainer(m_pHighBitDepthWindow, viewport());
  m_pHighBitDepthContainer->setAttribute(Qt::WA_TransparentForMouseEvents);
  m_pHighBitDepthContainer->setFocusPolicy(Qt::NoFocus);
  m_pHighBitDepthContainer->show();
  m_pScrollNavigator->setAttribute(Qt::WA_NativeWindow);
  m_pScrollNavigator->raise();

  QPixmap currentPixmap = m_pPreviewLabel->pixmap();
  if (!currentPixmap.isNull()) m_pHighBitDepthWindow->setFrame(currentPixmap.toImage());
  updateHighBitDepthView();
#else
  Q_UNUSED(a_enabled);
#endif
}

bool PreviewArea::eventFilter(QObject *a_pObject, QEvent *a_pEvent)
{
  if ((a_pObject == m_pPreviewLabel || a_pObject == viewport()) && (a_pEvent->type() == QEvent::Move || a_pEvent->type() == QEvent::Resize))
    updateHighBitDepthView();
  return QScrollArea::eventFilter(a_pObject, a_pEvent);
}

void PreviewArea::updateHighBitDepthView()
{
#ifdef Q_OS_WIN
  if (!m_pHighBitDepthWindow) return;
  m_pHighBitDepthContainer->setGeometry(viewport()->rect());
  double ratio = devicePixelRatioF();
  m_pHighBitDepthWindow->setFrameOffset(QPoint(qRound(m_pPreviewLabel->x() * ratio), qRound(m_pPreviewLabel->y() * ratio)));
  m_pHighBitDepthWindow->setBackground(viewport()->palette().color(viewport()->backgroundRole()));
#endif
}
