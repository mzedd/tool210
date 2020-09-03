#include "cliplistmodel.h"
#include "models/Demo.h"

ClipListModel::ClipListModel(QObject *parent) :
    QAbstractListModel(parent),
    selectedClip_(nullptr)
{

}

int ClipListModel::rowCount(const QModelIndex&) const
{
    return clipList->size();
}

QVariant ClipListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return  QVariant();

    Clip *clip = clipList->at(index.row());

    switch (role) {
    case ClipName:
        return QVariant(clip->name());
        break;
    case ClipDuration:
        return QVariant(clip->duration());
    }

    return QVariant();
}

bool ClipListModel::moveRows(const QModelIndex& /*sourceParent*/, int sourceRow, int /*count*/, const QModelIndex &destinationParent, int /*destinationChild*/)
{
    Clip *tmp = clipList->at(sourceRow);
    clipList->at(sourceRow) = clipList->at(destinationParent.row());
    clipList->at(destinationParent.row()) = tmp;

    return true;
}

Clip *ClipListModel::selectedClip() const
{
    return selectedClip_;
}

void ClipListModel::setSelectedClip(int id)
{
    Clip *clip = clipList->at(id);

    if(selectedClip_)
        disconnect(selectedClip_, &Clip::durationChanged, this, &ClipListModel::selectedClipDurationChanged);

    selectedClip_ = clip;
    if(selectedClip_ == nullptr)
        return;

    connect(selectedClip_, &Clip::durationChanged, this, &ClipListModel::selectedClipDurationChanged);

    emit selectedClipChanged(index(id, 0));
}

void ClipListModel::setClipList(std::vector<Clip *> *clipList)
{
    this->clipList = clipList;
}
