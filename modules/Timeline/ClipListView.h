#ifndef CLIPLISTVIEW_H
#define CLIPLISTVIEW_H

#include <QAbstractItemView>
#include <QWheelEvent>

class ClipListView : public QAbstractItemView
{
    Q_OBJECT

public:
    ClipListView(QWidget *parent = nullptr);

    QRect visualRect(const QModelIndex &index) const;
    void scrollTo(const QModelIndex &index, QAbstractItemView::ScrollHint hint = EnsureVisible);
    QModelIndex indexAt(const QPoint &point) const;

protected:
    QModelIndex moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers);
    int horizontalOffset() const;
    int verticalOffset() const;
    bool isIndexHidden(const QModelIndex &index) const;
    void setSelection(const QRect &rect, QItemSelectionModel::SelectionFlags command);

    void mousePressEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

    void paintEvent(QPaintEvent *event);

    QRegion visualRegionForSelection(const QItemSelection &selection) const;

private:
    float zoom;
    float time;

signals:
    void zoomChanged(float zoom);
    void timeChanged(float time);
};

#endif // CLIPLISTVIEW_H
