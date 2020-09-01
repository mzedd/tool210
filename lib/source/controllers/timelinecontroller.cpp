#include "timelinecontroller.h"

TimelineController::TimelineController(QObject *parent) : QObject(parent)
{

}

void TimelineController::setModel(ClipListModel *model)
{
    this->model = model;
    model->setParent(this);
}

void TimelineController::setSelectedIndex(int id)
{
    model;
}
