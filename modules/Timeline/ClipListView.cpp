#include "ClipListView.h"
#include <QPainter>

constexpr int CLIP_HEIGHT = 50;
constexpr int CLIP_NAME_COLUMN = 0;
constexpr int CLIP_DURATION_COLUMN = 1;
constexpr int TIMEAXIS_HEIGHT = 30;

ClipListView::ClipListView(QWidget *parent) :
    QAbstractItemView(parent)
{

}

QRect ClipListView::visualRect(const QModelIndex &index) const
{
    QModelIndex clipDurationIndex;
    float clipStartTime = 0.0f;

    for(int i = 0; i < index.row()-1; i++) {
        clipDurationIndex = model()->index(i, CLIP_DURATION_COLUMN);
        clipStartTime += model()->data(clipDurationIndex).toFloat();
    }

    clipDurationIndex = model()->index(index.row(), CLIP_DURATION_COLUMN);

    int xTopLeft = static_cast<int>(clipStartTime);
    int yTopLeft = TIMEAXIS_HEIGHT;
    int width = model()->data(clipDurationIndex).toInt();
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

void ClipListView::paintEvent(QPaintEvent*)
{
    QPainter painter(this->viewport());
    QPen pen;

    pen.setColor(Qt::black);
    pen.setStyle(Qt::PenStyle::SolidLine);
    pen.setWidth(1);
    painter.setPen(pen);

    painter.drawRect(5, 5, 200, 200);
}

QRegion ClipListView::visualRegionForSelection(const QItemSelection& /*selection*/) const
{
    return QRegion(rect());
}
