#ifndef SCENELISTMODEL_H
#define SCENELISTMODEL_H

#include <vector>
#include <QAbstractListModel>
#include "models/Scene.h"

class Q_DECL_EXPORT SceneListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit SceneListModel(QAbstractListModel *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void setSceneList(std::vector<Scene *> *sceneList);

private:
    std::vector<Scene *> *data_;

    enum SceneRoles {
        SceneName = Qt::UserRole + 1
    };

};

#endif // SCENELISTMODEL_H
