#ifndef TIMELINECONTROLLER_H
#define TIMELINECONTROLLER_H

#include <QObject>

class Q_DECL_EXPORT TimelineController : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(TimelineController)

public:
    explicit TimelineController(QObject *parent = nullptr);
    void setModel();

private:
    // model

Q_SIGNALS:
    void playPauseClicked();
    void timeChanged(float time);
    void clipClicked(int id);
    void clipsSwapped(int idA, int idB);
};

#endif // TIMELINECONTROLLER_H
