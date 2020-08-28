#include "ClipListModel.h"
#include "demo/Demo.h"

constexpr int CLIP_ATTRIBUTE_COUNT = 2;

ClipListModel::ClipListModel(QObject *parent) :
    QAbstractTableModel(parent)
{

}

int ClipListModel::rowCount(const QModelIndex&) const
{
    return Demo::instance().clipCount();
}

int ClipListModel::columnCount(const QModelIndex&) const
{
    return CLIP_ATTRIBUTE_COUNT;
}

QVariant ClipListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return  QVariant();

    Clip clip = Demo::instance().clipAt(index.row());

    if(role == Qt::DisplayRole)
    {
        switch (index.column()) {
        case 0:
            return QVariant(clip.getName());
            break;
        case 1:
            return QVariant(clip.getDuration());
        }
    }

    return QVariant();
}

bool ClipListModel::moveRows(const QModelIndex& /*sourceParent*/, int sourceRow, int /*count*/, const QModelIndex &destinationParent, int /*destinationChild*/)
{
    return Demo::instance().swapClips(sourceRow, destinationParent.row());
}
