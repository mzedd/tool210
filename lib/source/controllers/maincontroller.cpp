#include "maincontroller.h"

#include <QDebug>

MainController::MainController(QObject *parent) :
    QObject(parent),
    timelineController_(new TimelineController(this)),
    clipScreenController_(new ClipScreenController(this))
{
    connect(timelineController_, SIGNAL(playPauseClicked()), this, SLOT(handlePlayPauseClicked()));
    connect(timelineController_, SIGNAL(addClip()), this, SLOT(handleAddClip()));
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

void MainController::setModel(Demo *demo)
{
    this->demo = demo;
    connect(demo, SIGNAL(clipToRenderChanged(int)), this, SLOT(handleClipToRenderChanged(int)));
}

void MainController::handlePlayPauseClicked()
{
    qDebug() << "MainControlle::handlePlayPauseClicked";
}

void MainController::handleTimeChanged(float time)
{
    demo->checkClipToBeRenderdChangedAt(time);
    clipsScreenController()->setTime(time);
}

void MainController::handleAddClip()
{
    demo->addClip();
}

void MainController::handleClipToRenderChanged(int id)
{
    if(id < 0)
        clipScreenController_->setClipToRender(nullptr);
    else
        clipScreenController_->setClipToRender(&demo->clipList()->at(id));
}
