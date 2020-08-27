#include "ClipListView.h"
#include <QPainter>

#include <QDebug>

constexpr int CLIP_HEIGHT = 50;
constexpr int CLIP_NAME_COLUMN = 0;
constexpr int CLIP_DURATION_COLUMN = 1;
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
    time(TIME_CURSOR_DEFAULT)
{

}

QRect ClipListView::visualRect(const QModelIndex &index) const
{
    QModelIndex clipDurationIndex;
    float clipStartTime = 0.0f;

    for(int i = 0; i < index.row(); i++) {
        clipDurationIndex = model()->index(i, CLIP_DURATION_COLUMN);
        clipStartTime += model()->data(clipDurationIndex).toFloat();
    }

    clipDurationIndex = model()->index(index.row(), CLIP_DURATION_COLUMN);

    int xTopLeft = static_cast<int>(clipStartTime) * PIXEL_PER_SECOND * zoom;
    int yTopLeft = TIMEAXIS_HEIGHT;
    int width = model()->data(clipDurationIndex).toInt() * PIXEL_PER_SECOND * zoom;
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
        clipModelIndex = model()->index(i, CLIP_DURATION_COLUMN);
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
                return model()->index(current.row() - 1, current.column());
            }
            break;
        case MoveRight:
            if(current.row() < model()->rowCount()) {
                return model()->index(current.row() + 1, current.column());
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
    if(event->y() <= TIMEAXIS_HEIGHT) {
        time = event->x() / (PIXEL_PER_SECOND * zoom);
    }

    emit timeChanged(time);
    viewport()->update();

    QAbstractItemView::mousePressEvent(event);
}

void ClipListView::wheelEvent(QWheelEvent *event)
{
    zoom += event->pixelDelta().y() * SCROLL_SENSITIVITY;
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
        QModelIndex index = model()->index(i, CLIP_NAME_COLUMN);

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
