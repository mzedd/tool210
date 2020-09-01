#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>

#include "timelinecontroller.h"

class Q_DECL_EXPORT MainController : public QObject
{
    Q_OBJECT
public:
    explicit MainController(QObject *parent = nullptr);
    TimelineController* timelineController() const;

private:
    TimelineController *timelineController_;
    // Demo model

private Q_SLOTS:
    void handlePlayPauseClicked();
    void handleTimeChanged(float time);

};

#endif // MAINCONTROLLER_H
