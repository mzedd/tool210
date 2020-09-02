#include "timelinecontroller.h"

TimelineController::TimelineController(QObject *parent) : QObject(parent)
{

}

void TimelineController::setModel(ClipListModel *model)
{
    this->model = model;
    model->setParent(this);
}

void TimelineController::setTime(float time)
{
    emit timeChanged(time);
}

void TimelineController::setSelectedClip(int id)
{
    model->setSelectedClip(id);
}
