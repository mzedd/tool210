#include "clipinspectormodel.h"

ClipInspectorModel::ClipInspectorModel(QObject *parent) :
    QObject(parent),
    selectedClip_(nullptr),
    clipList_(nullptr),
    sceneList_(nullptr)
{

}

Clip *ClipInspectorModel::selectedClip() const
{
    return selectedClip_;
}

void ClipInspectorModel::setSelectedClip(Clip *clip)
{
    selectedClip_ = clip;
    emit selectedClipChanged();
}

ClipListModel *ClipInspectorModel::clipList() const
{
    return clipList_;
}

void ClipInspectorModel::setClipListModel(ClipListModel *model)
{
    clipList_ = model;
}

SceneListModel *ClipInspectorModel::sceneList() const
{
    return sceneList_;
}

void ClipInspectorModel::setSceneListModel(SceneListModel *model)
{
    sceneList_ = model;
    sceneList_->setParent(this);
}
