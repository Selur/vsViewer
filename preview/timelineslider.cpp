#include <QKeyEvent>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QWheelEvent>
#include <QPoint>
#include <QPainter>
#include <QMargins>
#include <QToolTip>
#include <QFontMetricsF>
#include <climits>
#include <cmath>
#include <cstdlib>

#include "common/helpers.h"

#include "timelineslider.h"

//==============================================================================

TimeLineSlider::TimeLineSlider(QWidget * a_pParent)
    : QWidget(a_pParent), m_maxFrame(999), m_fps(0.0), m_currentFrame(0), m_pointerAtFrame(0),
        m_displayMode(Time), m_bigStep(10), m_sideMargin(6), m_bottomMargin(2),
        m_slideLineHeight(10), m_slideLineFrameWidth(1), m_slideLineTicksSpacing(1),
        m_shortTickHeight(2), m_mediumTickHeight(3), m_longTickHeight(4), m_tickTextSpacing(1),
        m_textHeight(5), m_topMargin(2), m_minimumTicksSpacing(4), m_sliderPressed(false),
        m_labelsFont("Digital Mini")
{
  setAutoFillBackground(true);
  setFocusPolicy(Qt::StrongFocus);
  setMouseTracking(true);

  QFontMetricsF metrics(m_labelsFont);
  qreal factor = (qreal) m_textHeight / metrics.tightBoundingRect("9").height();
  m_labelsFont.setPointSizeF(m_labelsFont.pointSizeF() * factor);

  setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

  recalculateMinimumSize();
}

// END OF TimeLineSlider::TimeLineSlider(QWidget * a_pParent)
//==============================================================================

TimeLineSlider::~TimeLineSlider()
{

}

// END OF TimeLineSlider::TimeLineSlider(QWidget * a_pParent)
//==============================================================================

int TimeLineSlider::frame() const
{
  return m_currentFrame;
}

// END OF int TimeLineSlider::frame() const
//==============================================================================

void TimeLineSlider::setFrame(int a_frame)
{
  int oldCurrentFrame = m_currentFrame;
  if (a_frame > m_maxFrame)
    m_currentFrame = m_maxFrame;
  else
    m_currentFrame = a_frame;

  if (m_currentFrame != m_pointerAtFrame)
    m_pointerAtFrame = m_currentFrame;

  if (m_currentFrame == oldCurrentFrame)
    return;

  repaint();
  emit signalFrameChanged(m_currentFrame);
}

// END OF void TimeLineSlider::setFrame(int a_frame)
//==============================================================================

void TimeLineSlider::setFramesNumber(int a_framesNumber)
{
  m_maxFrame = a_framesNumber - 1;
  if (m_currentFrame > m_maxFrame)
    setFrame(m_maxFrame);
  repaint();
}

// END OF void TimeLineSlider::setFramesNumber(int a_framesNumber)
//==============================================================================

void TimeLineSlider::setFPS(double a_fps)
{
  m_fps = a_fps;
  repaint();
}

// END OF void TimeLineSlider::setFPS(double a_fps)
//==============================================================================

TimeLineSlider::DisplayMode TimeLineSlider::displayMode() const
{
  return m_displayMode;
}

// END OF DisplayMode TimeLineSlider::displayMode() const
//==============================================================================

void TimeLineSlider::setDisplayMode(DisplayMode a_displayMode)
{
  m_displayMode = a_displayMode;
  repaint();
}

// END OF void TimeLineSlider::setDisplayMode(DisplayMode a_displayMode)
//==============================================================================

void TimeLineSlider::setBigStep(int a_bigStep)
{
  m_bigStep = std::abs(a_bigStep);
}

// END OF void TimeLineSlider::setBigStep(int a_bigStep)
//==============================================================================

void TimeLineSlider::setLabelsFont(const QFont & a_font)
{
  m_labelsFont = a_font;
  QFontMetrics metrics(m_labelsFont);
  m_textHeight = metrics.tightBoundingRect("9").height();
  recalculateMinimumSize();
}

// END OF void TimeLineSlider::setLabelsFont(const QFont & a_font)
//==============================================================================

void TimeLineSlider::slotStepUp()
{
  if (m_currentFrame < m_maxFrame)
    setFrame(m_currentFrame + 1);
}

// END OF void TimeLineSlider::slotStepUp()
//==============================================================================

void TimeLineSlider::slotStepDown()
{
  if (m_currentFrame > 0)
    setFrame(m_currentFrame - 1);
}

// END OF void TimeLineSlider::slotStepDown()
//==============================================================================

void TimeLineSlider::slotBigStepUp()
{
  if (m_bigStep <= (m_maxFrame - m_currentFrame))
    setFrame(m_currentFrame + m_bigStep);
  else
    setFrame(m_maxFrame);
}

// END OF void TimeLineSlider::slotBigStepUp()
//==============================================================================

void TimeLineSlider::slotBigStepDown()
{
  if (m_bigStep <= m_currentFrame)
    setFrame(m_currentFrame - m_bigStep);
  else
    setFrame(0);
}

// END OF void TimeLineSlider::slotBigStepDown()
//==============================================================================

void TimeLineSlider::slotStepBy(int a_step)
{
  if (a_step < 0) {
    if (-a_step <= m_currentFrame)
      setFrame(m_currentFrame + a_step);
    else
      setFrame(0);
  } else {
    if (a_step <= (m_maxFrame - m_currentFrame))
      setFrame(m_currentFrame + a_step);
    else
      setFrame(m_maxFrame);
  }
}

// END OF void TimeLineSlider::slotStepBy(int a_step)
//==============================================================================

void TimeLineSlider::slotStepBySeconds(double a_seconds)
{
  if (m_fps == 0.0)
    return;

  int framesStep = std::round(a_seconds * m_fps);
  slotStepBy(framesStep);
}

// END OF void TimeLineSlider::slotStepBySeconds(double a_seconds)
//==============================================================================

void TimeLineSlider::keyPressEvent(QKeyEvent * a_pEvent)
{
  if (a_pEvent->modifiers() != Qt::NoModifier) {
    QWidget::keyPressEvent(a_pEvent);
    return;
  }

  int key = a_pEvent->key();
  if ((key == Qt::Key_Left) || (key == Qt::Key_Down)) {
    slotStepDown();
    a_pEvent->accept();
    return;
  } else if ((key == Qt::Key_Right) || (key == Qt::Key_Up)) {
    slotStepUp();
    a_pEvent->accept();
    return;
  } else if (key == Qt::Key_PageUp) {
    slotBigStepUp();
    a_pEvent->accept();
    return;
  } else if (key == Qt::Key_PageDown) {
    slotBigStepDown();
    a_pEvent->accept();
    return;
  } else if (key == Qt::Key_Home) {
    setFrame(0);
    a_pEvent->accept();
    return;
  } else if (key == Qt::Key_End) {
    setFrame(m_maxFrame);
    a_pEvent->accept();
    return;
  }

  QWidget::keyPressEvent(a_pEvent);
}

// END OF void TimeLineSlider::keyPressEvent(QKeyEvent * a_pEvent)
//==============================================================================

void TimeLineSlider::mouseMoveEvent(QMouseEvent * a_pEvent)
{
  if (m_sliderPressed) {
    m_pointerAtFrame = posToFrame(a_pEvent->pos().x());
    repaint();
    emit signalSliderMoved(m_pointerAtFrame);
  }

  if (m_sliderPressed || slideLineActiveRect().contains(a_pEvent->pos())) {
    int l_frame = m_sliderPressed ? m_pointerAtFrame : posToFrame(a_pEvent->pos().x());
    QString tipString = QString::number(l_frame);
    if (m_fps != 0.0) {
      tipString += " - ";
      tipString += vsedit::timeToString(((double) l_frame) / m_fps);
    }
    QToolTip::showText(a_pEvent->globalPos(), tipString);
  }

  QWidget::mouseMoveEvent(a_pEvent);
}

// END OF void TimeLineSlider::mouseMoveEvent(QMouseEvent * a_pEvent)
//==============================================================================

void TimeLineSlider::mousePressEvent(QMouseEvent * a_pEvent)
{
  if (slideLineActiveRect().contains(a_pEvent->pos())) {
    m_sliderPressed = true;
    m_pointerAtFrame = posToFrame(a_pEvent->pos().x());
    repaint();
    emit signalSliderPressed();
  }

  QWidget::mousePressEvent(a_pEvent);
}

// END OF void TimeLineSlider::mousePressEvent(QMouseEvent * a_pEvent)
//==============================================================================

void TimeLineSlider::mouseReleaseEvent(QMouseEvent * a_pEvent)
{
  bool emitSignal = m_sliderPressed;
  m_sliderPressed = false;
  setFrame(m_pointerAtFrame);
  if (emitSignal)
    emit signalSliderReleased();
  QWidget::mouseReleaseEvent(a_pEvent);
}

// END OF void TimeLineSlider::mouseReleaseEvent(QMouseEvent * a_pEvent)
//==============================================================================

void TimeLineSlider::paintEvent(QPaintEvent * a_pEvent)
{
  if (slideLineActiveRect().width() < 2) {
    a_pEvent->ignore();
    return;
  }

  QPainter painter(this);

  // Slide line
  QRect l_slideLineRect = slideLineRect();
  painter.setBrush(palette().color(QPalette::Base));
  QPen pen = painter.pen();
  QColor frameColor;
  if (hasFocus())
    frameColor = QColor("#4DBBFF");
  else
    frameColor = palette().color(QPalette::Dark);
  pen.setColor(frameColor);
  pen.setWidth(m_slideLineFrameWidth);
  painter.setPen(pen);
  QMargins slideLineMargins(0, 0, m_slideLineFrameWidth, m_slideLineFrameWidth);
  painter.drawRect(l_slideLineRect.marginsRemoved(slideLineMargins));

  // Current frame pointer
  pen.setColor(Qt::lightGray);
  pen.setWidth(1);
  painter.setPen(pen);
  int pointerPos = frameToPos(m_currentFrame);
  int pointerTop = l_slideLineRect.top() + m_slideLineFrameWidth;
  int pointerBottom = l_slideLineRect.bottom() - m_slideLineFrameWidth;
  painter.drawLine(pointerPos, pointerTop, pointerPos, pointerBottom);

  // Sliding frame pointer
  painter.setPen(Qt::black);
  pointerPos = frameToPos(m_pointerAtFrame);
  painter.drawLine(pointerPos, pointerTop, pointerPos, pointerBottom);

  // Ruler
  DisplayMode l_displayMode = Time;
  if ((m_displayMode == Frames) || (m_fps == 0.0))
    l_displayMode = Frames;

  double unitsInPixel = (double) m_maxFrame / (double) (slideLineInnerWidth() - 1);
  double maxUnits = (double) m_maxFrame;

  bool ticksAtExactFrames = (unitsInPixel < 1.0 / (double) m_minimumTicksSpacing);

  if (l_displayMode == Time) {
    unitsInPixel /= m_fps;
    maxUnits /= m_fps;
  }

  painter.setFont(m_labelsFont);

  int tickBottom = height() - m_bottomMargin - m_slideLineHeight - m_slideLineTicksSpacing - 1;
  int shortTickTop = tickBottom - m_shortTickHeight + 1;
  int mediumTickTop = tickBottom - m_mediumTickHeight + 1;
  int longTickTop = tickBottom - m_longTickHeight + 1;
  int startPos = m_sideMargin + m_slideLineFrameWidth;

  QPoint labelPos(0, longTickTop - m_tickTextSpacing);
  QFontMetricsF labelsFontMetrics(m_labelsFont);

  if (ticksAtExactFrames) {
    for (int n = 0; n <= m_maxFrame; ++n) {
      int tickPos = frameToPos(n);
      if (n % 10 == 0) {
        painter.drawLine(tickPos, longTickTop, tickPos, tickBottom);

        QString labelString;
        if (l_displayMode == Frames)
          labelString = QString::number(n);
        else
          labelString = vsedit::timeToString(((double) n) / m_fps);
#if (QT_VERSION >= QT_VERSION_CHECK(6,0,0))
        labelPos.setX(tickPos - labelsFontMetrics.horizontalAdvance(labelString) / 2 + 1);
#else
        labelPos.setX(tickPos - labelsFontMetrics.width(labelString) / 2 + 1);
#endif
        painter.drawText(labelPos, labelString);
      } else if (n % 5 == 0)
        painter.drawLine(tickPos, mediumTickTop, tickPos, tickBottom);
      else
        painter.drawLine(tickPos, shortTickTop, tickPos, tickBottom);
    }
  } else {
    double minUnitsPerTick = unitsInPixel * (double) m_minimumTicksSpacing;
    double unitsPerTick = std::pow(10.0, std::floor(std::log10((double) maxUnits)));
    while (unitsPerTick > minUnitsPerTick)
      unitsPerTick /= 10.0;

    // Do sane division for seconds and minutes.
    if ((l_displayMode == Time) && (minUnitsPerTick > 0.1)) {
      unitsPerTick = 0.2; // 2 sec
      if (unitsPerTick < minUnitsPerTick)
        unitsPerTick *= 2.5; // 5 sec
      if (unitsPerTick < minUnitsPerTick)
        unitsPerTick *= 2.0; // 10 sec
      if (unitsPerTick < minUnitsPerTick)
        unitsPerTick *= 2.0; // 20 sec
      if (unitsPerTick < minUnitsPerTick)
        unitsPerTick *= 1.5; // 30 sec
      if (unitsPerTick < minUnitsPerTick)
        unitsPerTick *= 2.0; // 1 min
      if (unitsPerTick < minUnitsPerTick)
        unitsPerTick *= 2.0; // 2 min
      if (unitsPerTick < minUnitsPerTick)
        unitsPerTick *= 2.5; // 5 min
      if (unitsPerTick < minUnitsPerTick)
        unitsPerTick *= 2.0; // 10 min
      if (unitsPerTick < minUnitsPerTick)
        unitsPerTick *= 2.0; // 20 min
      if (unitsPerTick < minUnitsPerTick)
        unitsPerTick *= 1.5; // 30 min
      if (unitsPerTick < minUnitsPerTick)
        unitsPerTick *= 2.0; // 1 hour
    }

    while (unitsPerTick < minUnitsPerTick) {
      unitsPerTick *= 2.0;
      if (unitsPerTick < minUnitsPerTick)
        unitsPerTick *= 1.25;
      if (unitsPerTick < minUnitsPerTick)
        unitsPerTick *= 2.0;
      if (unitsPerTick < minUnitsPerTick)
        unitsPerTick *= 2.0;
    }

    double units = 0.0;
    int n = 0;
    while (units - maxUnits < 0.001) {
      int tickPos = startPos + (int) (units / unitsInPixel);
      if (n % 10 == 0) {
        painter.drawLine(tickPos, longTickTop, tickPos, tickBottom);

        QString labelString;
        if (l_displayMode == Frames)
          labelString = QString::number(units);
        else
          labelString = vsedit::timeToString(units);
#if (QT_VERSION >= QT_VERSION_CHECK(6,0,0))
        labelPos.setX(tickPos - labelsFontMetrics.horizontalAdvance(labelString) / 2 + 1);
#else
        labelPos.setX(tickPos - labelsFontMetrics.width(labelString) / 2 + 1);
#endif
        painter.drawText(labelPos, labelString);
      } else if (n % 5 == 0)
        painter.drawLine(tickPos, mediumTickTop, tickPos, tickBottom);
      else
        painter.drawLine(tickPos, shortTickTop, tickPos, tickBottom);
      n++;
      units += unitsPerTick;
    }
  }

  a_pEvent->accept();
}

// END OF void TimeLineSlider::paintEvent(QPaintEvent * a_pEvent)
//==============================================================================

void TimeLineSlider::wheelEvent(QWheelEvent * a_pEvent)
{
  if (a_pEvent->modifiers() != Qt::NoModifier) {
    QWidget::wheelEvent(a_pEvent);
    return;
  }

  QPoint delta = a_pEvent->angleDelta();
  if (delta.x() == 0) {
    if (delta.y() < 0)
      slotStepDown();
    else
      slotStepUp();
  } else {
    if (delta.x() < 0)
      slotStepDown();
    else
      slotStepUp();
  }
  a_pEvent->accept();
}

// END OF void TimeLineSlider::wheelEvent(QWheelEvent * a_pEvent)
//==============================================================================

int TimeLineSlider::slideLineInnerWidth() const
{
  int l_slideLineInnerWidth = width() - m_sideMargin * 2 - m_slideLineFrameWidth * 2;
  return l_slideLineInnerWidth;
}

// END OF int TimeLineSlider::slideLineInnerWidth() const
//==============================================================================

int TimeLineSlider::frameToPos(int a_frame) const
{
  if (a_frame > m_maxFrame)
    a_frame = m_maxFrame;
  int framePos = (int) ((double) (slideLineInnerWidth() - 1) / (double) m_maxFrame
      * (double) a_frame);
  framePos += m_sideMargin + m_slideLineFrameWidth;
  return framePos;
}

// END OF int TimeLineSlider::frameToPos(int a_frame) const
//==============================================================================

int TimeLineSlider::posToFrame(int a_pos) const
{
  int start = m_sideMargin + m_slideLineFrameWidth;
  int last = width() - m_sideMargin - m_slideLineFrameWidth - 1;
  if (a_pos < start)
    return 0;
  else if (a_pos > last)
    return m_maxFrame;

  int l_frame = (int) std::round(
      (double) m_maxFrame / (double) (slideLineInnerWidth() - 1) * (double) (a_pos - start));
  return l_frame;
}

// END OF int TimeLineSlider::posToFrame(int a_pos) const
//==============================================================================

QRect TimeLineSlider::slideLineRect() const
{
  QRect l_slideLineRect;
  l_slideLineRect.setLeft(m_sideMargin);
  int slideLineWidth = width() - m_sideMargin * 2;
  l_slideLineRect.setWidth(slideLineWidth);
  l_slideLineRect.setTop(height() - m_bottomMargin - m_slideLineHeight);
  l_slideLineRect.setHeight(m_slideLineHeight);
  return l_slideLineRect;
}

// END OF QRect TimeLineSlider::slideLineRect() const
//==============================================================================

QRect TimeLineSlider::slideLineActiveRect() const
{
  QMargins margins(m_slideLineFrameWidth, m_slideLineFrameWidth, m_slideLineFrameWidth,
      m_slideLineFrameWidth);
  return slideLineRect().marginsRemoved(margins);
}

// END OF QRect TimeLineSlider::slideLineActiveRect() const
//==============================================================================

void TimeLineSlider::recalculateMinimumSize()
{
  int widgetHeight = m_bottomMargin + m_slideLineHeight + m_slideLineTicksSpacing + m_longTickHeight
      + m_tickTextSpacing + m_textHeight + m_topMargin;
  setMinimumSize(2 * m_sideMargin + 2 * m_slideLineFrameWidth + 2, widgetHeight);
}

// END OF QRect TimeLineSlider::recalculateMinimumSize()
//==============================================================================
