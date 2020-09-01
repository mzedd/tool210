#include "cliplistmodel.h"
#include "models/Demo.h"

ClipListModel::ClipListModel(QObject *parent) :
    QAbstractListModel(parent)
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

    Clip clip = clipList->at(index.row());

    switch (role) {
    case ClipName:
        return QVariant(clip.getName());
        break;
    case ClipDuration:
        return QVariant(clip.getDuration());
    }

    return QVariant();
}

bool ClipListModel::moveRows(const QModelIndex& /*sourceParent*/, int sourceRow, int /*count*/, const QModelIndex &destinationParent, int /*destinationChild*/)
{
    Clip tmp = clipList->at(sourceRow);
    clipList->at(sourceRow) = clipList->at(destinationParent.row());
    clipList->at(destinationParent.row()) = tmp;

    return true;
}

void ClipListModel::setClipList(std::vector<Clip> *clipList)
{
    this->clipList = clipList;
}
