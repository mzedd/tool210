#include "clipinspectormodel.h"

ClipInspectorModel::ClipInspectorModel(QObject *parent) :
    QObject(parent),
    selectedClip_(nullptr)
{

}

void ClipInspectorModel::setSceneList(std::vector<Scene *> *sceneList)
{
    this->sceneList = sceneList;
}

Clip *ClipInspectorModel::selectedClip() const
{
    return selectedClip_;
}

void ClipInspectorModel::setSelectedClip(Clip *clip)
{
    selectedClip_ = clip;
    emit selectedClipNameChanged();
    emit selectedClipDurationChanged();
}

void ClipInspectorModel::setSelectedClipName(const QString& name)
{
    selectedClip()->setName(name);
    emit selectedClipNameChanged();
}
