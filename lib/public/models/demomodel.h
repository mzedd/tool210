#ifndef DEMOMODEL_H
#define DEMOMODEL_H

#include <QAbstractItemModel>
#include "Demo.h"

class Q_DECL_EXPORT DemoModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit DemoModel(QObject *parent = nullptr);
    ~DemoModel();

    Demo *demo() const;
    void setDemo(Demo *demo);

    void addClip();
    void addScene();
    void checkClipToBeRenderdChangedAt(float time);

    // QAbstractItemModel interface
    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

private:
    Demo *demo_;

Q_SIGNALS:
    void clipAdded(int id);
    void sceneAdded();
    void clipToRenderChanged(int id);

};

#endif // DEMOMODEL_H
