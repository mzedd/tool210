#ifndef TIMELINECONTROLLER_H
#define TIMELINECONTROLLER_H

#include <QObject>
#include "models/cliplistmodel.h"

class Q_DECL_EXPORT TimelineController : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(TimelineController)

public:
    explicit TimelineController(QObject *parent = nullptr);
    void setModel(ClipListModel *model);
    void setTime(float time);
    void setSelectedClip(int id);

private:
    ClipListModel *model;

Q_SIGNALS:
    void playPauseClicked();
    void timeChanged(float time);
    void addClip();
    void clipsSwapped(int idA, int idB);
    void clipSelected(int id);
};

#endif // TIMELINECONTROLLER_H
