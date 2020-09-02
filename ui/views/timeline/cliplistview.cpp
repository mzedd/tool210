#include "cliplistview.h"
#include <models/cliplistmodel.h>
#include <QPainter>

#include <QDebug>

constexpr int CLIP_HEIGHT = 50;
constexpr int TIMEAXIS_HEIGHT = 30;
constexpr int PIXEL_PER_SECOND = 5;
constexpr float SCROLL_SENSITIVITY = 0.01f;
constexpr float ZOOM_MINIMUM = 0.5f;
constexpr float ZOOM_MAXIMUM = 5.0f;
constexpr float ZOOM_DEFAULT = 1.0f;
constexpr float TIME_CURSOR_DEFAULT = 10.0f;

ClipListView::ClipListView(QWidget *parent) :
    QAbstractItemView(parent),
    zoom(ZOOM_DEFAULT),
    time(TIME_CURSOR_DEFAULT),
    timeCurorDragState(DragState::None),
    currentClipDragState(DragState::None)
{
    setMouseTracking(true);
}

QRect ClipListView::visualRect(const QModelIndex &index) const
{
    QModelIndex clipDurationIndex;
    float clipStartTime = 0.0f;

    for(int i = 0; i < index.row(); i++) {
        clipDurationIndex = model()->index(i, 0);
        clipStartTime += model()->data(clipDurationIndex, ClipListModel::ClipDuration).toFloat();
    }

    clipDurationIndex = model()->index(index.row(), 0);

    int xTopLeft = static_cast<int>(clipStartTime) * PIXEL_PER_SECOND * zoom;
    int yTopLeft = TIMEAXIS_HEIGHT;
    int width = model()->data(clipDurationIndex, ClipListModel::ClipDuration).toInt() * PIXEL_PER_SECOND * zoom;
    int height = CLIP_HEIGHT;

    return QRect(xTopLeft, yTopLeft, width, height);
}

void ClipListView::scrollTo(const QModelIndex& /*index*/, QAbstractItemView::ScrollHint /*hint*/)
{

}

QModelIndex ClipListView::indexAt(const QPoint &point) const
{
    QModelIndex clipModelIndex;

    for(int i = 0; i < model()->rowCount(); i++) {
        clipModelIndex = model()->index(i, 0);
        if(visualRect(clipModelIndex).contains(point)) {
            return  clipModelIndex;
        }
    }

    return QModelIndex();
}

QModelIndex ClipListView::moveCursor(QAbstractItemView::CursorAction cursorAction, Qt::KeyboardModifiers /*modifiers*/)
{
    QModelIndex current = currentIndex();

    switch (cursorAction) {
        case MoveLeft:
            if(current.row() > 0) {
                return model()->index(current.row() - 1, 0);
            }
            break;
        case MoveRight:
            if(current.row() < model()->rowCount()) {
                return model()->index(current.row() + 1, 0);
            }
            break;
        default:
            break;
    }

    return current;
}

int ClipListView::horizontalOffset() const
{
    return 0;
}

int ClipListView::verticalOffset() const
{
    return 0;
}

bool ClipListView::isIndexHidden(const QModelIndex& /*index*/) const
{
    return false;
}

void ClipListView::setSelection(const QRect& /*rect*/, QItemSelectionModel::SelectionFlags /*command*/)
{

}

void ClipListView::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::MouseButton::LeftButton) {
        if(isMouseFloatingOverTimeCursor(event->pos())) {
            timeCurorDragState = DragState::Dragged;
        } else {
            if(event->y() <= TIMEAXIS_HEIGHT) {
                time = event->x() / (PIXEL_PER_SECOND * zoom);
                emit timeChanged(time);
            } else {
                QModelIndex index = indexAt(event->pos());
                if(index.isValid()) {
                    setCurrentIndex(index);
                    currentClipDragState = DragState::Dragged;
                } else {
                    setCurrentIndex(QModelIndex());
                }
            }
        }
    }

    viewport()->update();
    QAbstractItemView::mousePressEvent(event);
}

void ClipListView::mouseMoveEvent(QMouseEvent *event)
{
    if(isMouseFloatingOverTimeCursor(event->pos())) {
        this->setCursor(Qt::CursorShape::SizeHorCursor);
    } else {
        this->setCursor(Qt::CursorShape::ArrowCursor);
    }

    if(timeCurorDragState == DragState::Dragged) {
        time = event->x() / (PIXEL_PER_SECOND * zoom);
        emit timeChanged(time);
        viewport()->update();
    }
}

void ClipListView::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::MouseButton::LeftButton) {
        if(isMouseFloatingOverTimeCursor(event->pos())) {
            timeCurorDragState = DragState::None;
            emit clipToRenderChanged(clipUnderTimeCursor());
        } else {
            QModelIndex index = indexAt(event->pos());
            if(index.isValid()) {
                model()->moveRow(currentIndex(), currentIndex().row(), index, index.row());
                setCurrentIndex(index);
            }
            currentClipDragState = DragState::None;
        }
    }

    viewport()->update();
}

void ClipListView::wheelEvent(QWheelEvent *event)
{
    QPoint pixelDelta = event->pixelDelta();

    if(pixelDelta.isNull()) {
        zoom += event->angleDelta().y() / 8 * SCROLL_SENSITIVITY;
    } else {
        zoom += event->pixelDelta().y() * SCROLL_SENSITIVITY;
    }

    zoom = qBound(ZOOM_MINIMUM, zoom, ZOOM_MAXIMUM);

    emit zoomChanged(zoom);
    viewport()->update();

    QAbstractItemView::wheelEvent(event);
}

void ClipListView::paintEvent(QPaintEvent*)
{
    QPainter painter(this->viewport());
    QPen pen;

    pen.setColor(Qt::black);
    pen.setStyle(Qt::PenStyle::SolidLine);
    pen.setWidth(1);
    painter.setPen(pen);

    // time axis
    int maxTickCount = (width() / (PIXEL_PER_SECOND * zoom));
    for(int i = 0; i < maxTickCount; i++) {
        float x = i * PIXEL_PER_SECOND * zoom;
        QLine tick(x, 0, x, 0);

        if(i % 10) {
            pen.setWidth(1);
            tick.setP2(QPoint(tick.x2(), TIMEAXIS_HEIGHT*0.6f));
        } else {
            pen.setWidth(2);
            tick.setP2(QPoint(tick.x2(), TIMEAXIS_HEIGHT*0.8f));
        }

        painter.setPen(pen);
        painter.drawLine(tick);
    }

    // draw vertical lines
    pen.setWidth(1);
    painter.setPen(pen);
    float y = 0.0f;
    QVector<QLineF> lines;
    int maxLineCount = (int)(height()/CLIP_HEIGHT);
    for(int i = 0; i < maxLineCount; i++) {
        y = i*CLIP_HEIGHT + TIMEAXIS_HEIGHT;
        lines.append(QLineF(0, y, width(), y));
    }
    painter.drawLines(lines);

    // draw clips
    for(int i = 0; i < model()->rowCount(); i++) {
        QModelIndex index = model()->index(i, 0);

        if(currentIndex() == index) {
            painter.setBrush(Qt::red);
        } else {
            painter.setBrush(Qt::blue);
        }

        painter.drawRect(visualRect(index));
    }

    // draw time cursor
    float x = time * PIXEL_PER_SECOND * zoom;
    QLine timeCursorLine(x, 0, x, height());
    pen.setColor(Qt::red);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawLine(timeCursorLine);
}

QRegion ClipListView::visualRegionForSelection(const QItemSelection& /*selection*/) const
{
    return QRegion(rect());
}

bool ClipListView::isMouseFloatingOverTimeCursor(const QPoint &point) const
{
    float x = time * PIXEL_PER_SECOND * zoom;
    QRect timeCursorRect(x - 1, 0, 3, height());
    return timeCursorRect.contains(point);
}

int ClipListView::clipUnderTimeCursor() const
{
    float x = time * PIXEL_PER_SECOND * zoom;
    return indexAt(QPoint(x, TIMEAXIS_HEIGHT + CLIP_HEIGHT * 0.5f)).row();
}

void ClipListView::setTime(float time)
{
    this->time = time;
    viewport()->update();
}

void ClipListView::selectedClipChanged(QModelIndex index)
{
    setCurrentIndex(index);
    viewport()->update();
}
