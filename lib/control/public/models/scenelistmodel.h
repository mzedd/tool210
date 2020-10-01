#ifndef SCENELISTMODEL_H
#define SCENELISTMODEL_H

#include <vector>
#include <QAbstractTableModel>
#include "Scene.h"

class Q_DECL_EXPORT SceneListModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit SceneListModel(QAbstractListModel *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    void setSceneList(std::vector<Scene *> *sceneList);

private:
    std::vector<Scene *> *data_;

    enum SceneRoles {
        SceneName = Qt::UserRole + 1
    };

};

#endif // SCENELISTMODEL_H
