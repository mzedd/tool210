#include "models/scenelistmodel.h"

SceneListModel::SceneListModel(QAbstractListModel *parent) :
    QAbstractListModel(parent),
    data_(nullptr)
{

}

int SceneListModel::rowCount(const QModelIndex& /*parent*/) const
{
    return static_cast<int>(data_->size());
}

QVariant SceneListModel::data(const QModelIndex &index, int role) const
{
    Scene *scene = data_->at(index.row());

    QVariant data;

    switch (role) {
        case Qt::DisplayRole:
        case SceneName:
            data.setValue(scene->name());
            break;
        default:
            return data;
    }

    return data;
}

void SceneListModel::setSceneList(std::vector<Scene *> *sceneList)
{
    data_ = sceneList;
}