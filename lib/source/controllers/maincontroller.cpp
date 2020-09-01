#include "maincontroller.h"

#include <QDebug>

MainController::MainController(QObject *parent) :
    QObject(parent),
    timelineController_(new TimelineController(this)),
    clipScreenController_(new ClipScreenController(this))
{
    connect(timelineController_, SIGNAL(playPauseClicked()), this, SLOT(handlePlayPauseClicked()));
    connect(timelineController_, SIGNAL(timeChanged(float)), this, SLOT(handleTimeChanged(float)));
}

TimelineController *MainController::timelineController() const
{
    return timelineController_;
}

ClipScreenController *MainController::clipsScreenController() const
{
    return clipScreenController_;
}

void MainController::handlePlayPauseClicked()
{
    qDebug() << "MainControlle::handlePlayPauseClicked";
}

void MainController::handleTimeChanged(float time)
{
    qDebug() << "MainControlle::handleTimeChanged to: " << time;
}
