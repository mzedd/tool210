#ifndef TIMELINE_H
#define TIMELINE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "cliplistview.h"
#include "models/cliplistmodel.h"
#include "controllers/timelinecontroller.h"

class RenderContext;

class TimelineView : public QWidget
{
    Q_OBJECT
public:
    explicit TimelineView(ClipListModel *model, QWidget *parent = nullptr);
    void setRenderContext(RenderContext* renderContext);

    ClipListView *clipListView;

private:
    RenderContext *renderContext;

    QPushButton *runPauseButton;
    QPushButton *addClipButton;
    QLabel *zoomLabel;
    QLabel *timeLabel;



private Q_SLOTS:
    void setZoomLabel(float zoom);
    void playPauseClicked();
    void updateTimeLabel();
    void addClipButtonClicked();

signals:
    void addClipClicked();
    void clipToRenderChanged(int id);
    void clipSelected(int id);
    void setCurrent(QModelIndex index);
};

#endif // TIMELINE_H
