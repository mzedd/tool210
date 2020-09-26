#include "clipinspectorcontroller.h"

ClipInspectorController::ClipInspectorController(QObject *parent) :
    QObject(parent),
    model(nullptr)
{

}

void ClipInspectorController::setModel(ClipInspectorModel *model)
{
    this->model = model;
    model->setParent(this);
}