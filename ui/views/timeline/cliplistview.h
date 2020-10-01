#ifndef CLIPLISTVIEW_H
#define CLIPLISTVIEW_H

#include <QAbstractItemView>
#include <QWheelEvent>

class RenderContext;

class ClipListView : public QAbstractItemView
{
    Q_OBJECT

public:
    ClipListView(QWidget *parent = nullptr);

    QRect visualRect(const QModelIndex &index) const;
    void scrollTo(const QModelIndex &index, QAbstractItemView::ScrollHint hint = EnsureVisible);
    QModelIndex indexAt(const QPoint &point) const;

    void setRenderContext(RenderContext *renderContext);

protected:
    QModelIndex moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers);
    int horizontalOffset() const;
    int verticalOffset() const;
    bool isIndexHidden(const QModelIndex &index) const;
    void setSelection(const QRect &rect, QItemSelectionModel::SelectionFlags command);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

    void paintEvent(QPaintEvent *event);

    QRegion visualRegionForSelection(const QItemSelection &selection) const;

private:
    RenderContext *renderContext;

    bool isMouseFloatingOverTimeCursor(const QPoint &point) const;
    int clipUnderTimeCursor() const;
    void setTimeFromCursorPosition(int x);
    float getCursorPosition() const;

    enum DragState {
        None,
        Dragged
    };

    float zoom;
    DragState timeCurorDragState;

Q_SIGNALS:
    void zoomChanged(float zoom);
    void clipSelected(int id);

public Q_SLOTS:
    void timeChanged();

protected Q_SLOTS:
    // QAbstractItemView interface
    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles);

};

#endif // CLIPLISTVIEW_H
