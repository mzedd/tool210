#ifndef TIMELINE_H
#define TIMELINE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "cliplistview.h"
#include "models/cliplistmodel.h"
#include "controllers/timelinecontroller.h"

class TimelineView : public QWidget
{
    Q_OBJECT
public:
    explicit TimelineView(ClipListModel *model, QWidget *parent = nullptr);
    void setController(TimelineController *timelineController);

    ClipListView *clipListView;

private:

    QPushButton *runPauseButton;
    QPushButton *addClipButton;
    QLabel *zoomLabel;
    QLabel *timeLabel;

private slots:
    void setZoomLabel(float zoom);
    void setTimeLabel(float time);
    void setTime(float time);

signals:
    void timeChanged(float time);
    void addClipClicked();
    void clipToRenderChanged(int id);
    void clipSelected(int id);
    void setCurrent(QModelIndex index);
};

#endif // TIMELINE_H
