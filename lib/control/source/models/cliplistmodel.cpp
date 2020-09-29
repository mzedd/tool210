#include "cliplistmodel.h"
#include "Demo.h"
#include "Clip.h"

#include <QDebug>

ClipListModel::ClipListModel(QObject *parent) :
    QAbstractTableModel(parent)
{

}

int ClipListModel::rowCount(const QModelIndex&) const
{
    return demo->clipList().size();
}

int ClipListModel::columnCount(const QModelIndex &/*parent*/) const
{
    return 2;
}

QVariant ClipListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return  QVariant();

    Clip *clip = demo->clipList().at(index.row());

    switch (role) {
    case Qt::DisplayRole:
    case Qt::EditRole:
        switch (index.column()) {
            case 0:
            return QVariant(QString::fromStdString(clip->name()));
            break;
        case 1:
            return QVariant(clip->duration());
            break;
        }
        break;
    case ClipName:
        return QVariant(QString::fromStdString(clip->name()));
        break;
    case ClipDuration:
        return QVariant(clip->duration());
    }

    return QVariant();
}

bool ClipListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    qDebug() << index;

    if(!(role == Qt::EditRole))
        return false;

    Clip *clip = demo->clipList().at(index.row());

    switch (index.column()) {
    case 0: // name
        clip->setName(value.toString().toStdString());
        break;
    case 1: // duration
        clip->setDuration(value.toFloat());
        break;
    }

    emit dataChanged(index, index);
    return true;
}

bool ClipListModel::moveRows(const QModelIndex& /*sourceParent*/, int sourceRow, int /*count*/, const QModelIndex &destinationParent, int /*destinationChild*/)
{
    Clip *tmp = demo->clipList().at(sourceRow);
    demo->clipList().at(sourceRow) = demo->clipList().at(destinationParent.row());
    demo->clipList().at(destinationParent.row()) = tmp;

    return true;
}

bool ClipListModel::insertRows(int /*row*/, int /*count*/, const QModelIndex &/*parent*/)
{
    demo->addClip();

    QModelIndex tmp = index(rowCount() - 1, 0);
    emit dataChanged(tmp, tmp);
    return true;
}

void ClipListModel::setDemo(Demo *demo)
{
    this->demo = demo;
}
