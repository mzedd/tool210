#include "cliplistmodel.h"
#include "models/Demo.h"

ClipListModel::ClipListModel(QObject *parent) :
    QAbstractListModel(parent)
{

}

int ClipListModel::rowCount(const QModelIndex&) const
{
    return Demo::instance().clipCount();
    return 5;
}

QVariant ClipListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return  QVariant();

    Clip clip = Demo::instance().clipAt(index.row());

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
    return Demo::instance().swapClips(sourceRow, destinationParent.row());
}
