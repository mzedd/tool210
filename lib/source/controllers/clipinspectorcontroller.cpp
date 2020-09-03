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

void ClipInspectorController::setSelectedClip(Clip *clip)
{
    model->setSelectedClip(clip);
}

void ClipInspectorController::selectedClipNameEdited(const QString &name)
{
    model->selectedClip()->setName(name);
}

void ClipInspectorController::selectedClipDurationEdited(const QString &name)
{
    model->selectedClip()->setDuration(name.toFloat());
}
