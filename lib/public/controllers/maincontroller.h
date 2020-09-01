#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>

#include "timelinecontroller.h"
#include "clipscreencontroller.h"
#include "models/Demo.h"

class Q_DECL_EXPORT MainController : public QObject
{
    Q_OBJECT
public:
    explicit MainController(QObject *parent = nullptr);
    TimelineController *timelineController() const;
    ClipScreenController *clipsScreenController() const;

private:
    TimelineController *timelineController_;
    ClipScreenController *clipScreenController_;

    // Demo model

private Q_SLOTS:
    void handlePlayPauseClicked();
    void handleTimeChanged(float time);

};

#endif // MAINCONTROLLER_H
