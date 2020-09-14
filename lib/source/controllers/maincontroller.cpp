#include "maincontroller.h"

#include <QDebug>

MainController::MainController(QObject *parent) :
    QObject(parent),
    timelineController_(new TimelineController(this)),
    clipScreenController_(new ClipScreenController(this)),
    clipInspectorController_(new ClipInspectorController(this))
{
    // TimelineController signals
    connect(timelineController_, SIGNAL(playPauseClicked()), this, SLOT(handlePlayPauseClicked()));
    connect(timelineController_, SIGNAL(addClip()), this, SLOT(handleAddClip()));
    connect(timelineController_, SIGNAL(timeChanged(float)), this, SLOT(handleTimeChanged(float)));
    connect(timelineController_, &TimelineController::clipSelected, this, &MainController::handleClipSelected);

    // ClipScreenController signals
    connect(clipScreenController_, SIGNAL(frameFinishedAt(float)), this, SLOT(handleFrameFinishedAt(float)));
}

TimelineController *MainController::timelineController() const
{
    return timelineController_;
}

ClipScreenController *MainController::clipsScreenController() const
{
    return clipScreenController_;
}

ClipInspectorController *MainController::clipInspectorController() const
{
    return  clipInspectorController_;
}

void MainController::setModel(Demo *demo)
{
    this->demo = demo;
    connect(demo, &Demo::clipToRenderChanged, this, &MainController::handleClipToRenderChanged);
    connect(demo, &Demo::clipAdded, this, &MainController::handleClipSelected);
}

void MainController::handleClipSelected(int id)
{
    timelineController()->setSelectedClip(id);
    clipInspectorController()->setSelectedClip(demo->clipList().at(id));
}

void MainController::handlePlayPauseClicked()
{
    clipsScreenController()->toggleRun();
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
        clipScreenController_->setClipToRender(demo->clipList().at(id));
}

void MainController::handleFrameFinishedAt(float time)
{
    demo->checkClipToBeRenderdChangedAt(time);
    timelineController()->setTime(time);
}
