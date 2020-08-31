#ifndef TIMELINE_H
#define TIMELINE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "cliplistview.h"
#include "models/cliplistmodel.h"

class TimelineView : public QWidget
{
    Q_OBJECT
public:
    explicit TimelineView(ClipListModel *model, QWidget *parent = nullptr);

private:
    ClipListView *clipListView;
    QPushButton *runPauseButton;
    QLabel *zoomLabel;
    QLabel *timeLabel;

private slots:
    void setZoomLabel(float zoom);
    void setTimeLabel(float time);
    void setTime(float time);

signals:
    void timeChanged(float time);
    void clipToRenderChanged(int id);
};

#endif // TIMELINE_H
