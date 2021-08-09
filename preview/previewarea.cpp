#include <QLabel>
#include <QKeyEvent>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QScrollBar>
#include <QCoreApplication>

#include "scrollnavigator.h"

#include "previewarea.h"

//==============================================================================

PreviewArea::PreviewArea(QWidget * a_pParent)
    : QScrollArea(a_pParent), m_pPreviewLabel(nullptr), m_pScrollNavigator(nullptr),
        m_draggingPreview(false), m_lastCursorPos(0, 0), m_lastPreviewLabelPos(0, 0)
{
  m_pPreviewLabel = new QLabel(this);
  m_pPreviewLabel->setAlignment(Qt::AlignTop | Qt::AlignLeft);
  QScrollArea::setWidget(m_pPreviewLabel);

  m_pScrollNavigator = new ScrollNavigator(this);
  int scrollFrameWidth = frameWidth();
  m_pScrollNavigator->move(pos() + QPoint(scrollFrameWidth, scrollFrameWidth));
  m_pScrollNavigator->setVisible(false);

  setMouseTracking(true);
  m_pPreviewLabel->setMouseTracking(true);
}

// END OF PreviewArea::PreviewArea(QWidget * a_pParent)
//==============================================================================

PreviewArea::~PreviewArea()
{

}

// END OF PreviewArea::~PreviewArea()
//==============================================================================

void PreviewArea::setPixmap(const QPixmap & a_pixmap)
{
  m_pPreviewLabel->setPixmap(a_pixmap);
}

// END OF void PreviewArea::setPixmap(const QPixmap & a_pixmap)
//==============================================================================

void PreviewArea::slotScrollLeft()
{
  horizontalScrollBar()->setValue(0);
}

// END OF void PreviewArea::slotScrollLeft()
//==============================================================================

void PreviewArea::slotScrollRight()
{
  QCoreApplication::processEvents();
  QScrollBar * pHorizontalScrollbar = horizontalScrollBar();
  pHorizontalScrollbar->setValue(pHorizontalScrollbar->maximum());
}

// END OF void PreviewArea::slotScrollRight()
//==============================================================================

void PreviewArea::slotScrollTop()
{
  verticalScrollBar()->setValue(0);
}

// END OF void PreviewArea::slotScrollTop()
//==============================================================================

void PreviewArea::slotScrollBottom()
{
  QCoreApplication::processEvents();
  QScrollBar * pVerticalScrollbar = verticalScrollBar();
  pVerticalScrollbar->setValue(pVerticalScrollbar->maximum());
}

// END OF void PreviewArea::slotScrollBottom()
//==============================================================================

void PreviewArea::resizeEvent(QResizeEvent * a_pEvent)
{
  QScrollArea::resizeEvent(a_pEvent);
  emit signalSizeChanged();
}

// END OF void PreviewArea::resizeEvent(QResizeEvent * a_pEvent)
//==============================================================================

void PreviewArea::keyPressEvent(QKeyEvent * a_pEvent)
{
  if (a_pEvent->modifiers() != Qt::NoModifier) {
    QScrollArea::keyPressEvent(a_pEvent);
    return;
  }

  int key = a_pEvent->key();
  int wantedKeys[] = { Qt::Key_Left, Qt::Key_Right, Qt::Key_Up, Qt::Key_Down, Qt::Key_PageUp,
          Qt::Key_PageDown, Qt::Key_Home, Qt::Key_End };
  int * pKeysEnd = wantedKeys + sizeof(wantedKeys) / sizeof(*wantedKeys);
  if (pKeysEnd != std::find(wantedKeys, pKeysEnd, key)) {
    a_pEvent->ignore();
    return;
  }

  QScrollArea::keyPressEvent(a_pEvent);
}

// END OF void PreviewArea::keyPressEvent(QKeyEvent * a_pEvent)
//==============================================================================

void PreviewArea::wheelEvent(QWheelEvent * a_pEvent)
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

void PreviewArea::mousePressEvent(QMouseEvent * a_pEvent)
{
  if (a_pEvent->buttons() == Qt::LeftButton) {
    m_draggingPreview = true;
    m_lastCursorPos = a_pEvent->globalPos();
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

void PreviewArea::mouseMoveEvent(QMouseEvent * a_pEvent)
{
  if ((a_pEvent->buttons() & Qt::LeftButton) && m_draggingPreview) {
    QPoint newCursorPos = a_pEvent->globalPos();
    QPoint posDifference = newCursorPos - m_lastCursorPos;
    QPoint newPreviewLabelPos = m_lastPreviewLabelPos + posDifference;

    horizontalScrollBar()->setValue(-newPreviewLabelPos.x());
    verticalScrollBar()->setValue(-newPreviewLabelPos.y());

    drawScrollNavigator();
    a_pEvent->accept();
    return;
  }

  QPoint globalPoint = a_pEvent->globalPos();
  QPoint imagePoint = m_pPreviewLabel->mapFromGlobal(globalPoint);
#if (QT_VERSION >= QT_VERSION_CHECK(6,0,0))
  const QPixmap pPreviewPixmap = m_pPreviewLabel->pixmap();
  int pixmapWidth = pPreviewPixmap.width();
  int pixmapHeight = pPreviewPixmap.height();
#else
  const QPixmap * pPreviewPixmap = m_pPreviewLabel->pixmap();
  int pixmapWidth = pPreviewPixmap->width();
  int pixmapHeight = pPreviewPixmap->height();
#endif
  if ((imagePoint.x() < pixmapWidth) && (imagePoint.y() < pixmapHeight)) {
    float normX = (float) imagePoint.x() / (float) pixmapWidth;
    float normY = (float) imagePoint.y() / (float) pixmapHeight;

    emit signalMouseOverPoint(normX, normY);
  }

  QScrollArea::mouseMoveEvent(a_pEvent);
}

// END OF void PreviewArea::mouseMoveEvent(QMouseEvent * a_pEvent)
//==============================================================================

void PreviewArea::mouseReleaseEvent(QMouseEvent * a_pEvent)
{
  Qt::MouseButton releasedButton = a_pEvent->button();
  if (releasedButton == Qt::LeftButton) {
    m_draggingPreview = false;
    m_pScrollNavigator->setVisible(false);
    a_pEvent->accept();
    return;
  }
#if (QT_VERSION >= QT_VERSION_CHECK(6,0,0))
  else if (releasedButton == Qt::MiddleButton)
    emit signalMouseMiddleButtonReleased();
#else
  else if (releasedButton == Qt::MidButton)
    emit signalMouseMiddleButtonReleased();
#endif
  else if (releasedButton == Qt::RightButton)
    emit signalMouseRightButtonReleased();

  QScrollArea::mouseReleaseEvent(a_pEvent);
}

// END OF void PreviewArea::mouseReleaseEvent(QMouseEvent * a_pEvent)
//==============================================================================

void PreviewArea::drawScrollNavigator()
{
#if (QT_VERSION >= QT_VERSION_CHECK(6,0,0))
  int contentsWidth = m_pPreviewLabel->pixmap().width();
  int contentsHeight = m_pPreviewLabel->pixmap().height();
#else
  int contentsWidth = m_pPreviewLabel->pixmap()->width();
  int contentsHeight = m_pPreviewLabel->pixmap()->height();
#endif
  int viewportX = -m_pPreviewLabel->x();
  int viewportY = -m_pPreviewLabel->y();
  int viewportWidth = viewport()->width();
  int viewportHeight = viewport()->height();

  m_pScrollNavigator->draw(contentsWidth, contentsHeight, viewportX, viewportY, viewportWidth,
      viewportHeight);
}

// END OF void PreviewArea::drawScrollNavigator()
//==============================================================================
