#ifndef CLIPLISTMODEL_H
#define CLIPLISTMODEL_H

#include <vector>
#include <QAbstractTableModel>

class Demo;

class Q_DECL_EXPORT ClipListModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    ClipListModel(QObject *parent  = nullptr);

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    bool moveRows(const QModelIndex &sourceParent, int sourceRow, int count, const QModelIndex &destinationParent, int destinationChild) override;
    bool insertRows(int row, int count, const QModelIndex &parent) override;

    void setDemo(Demo *demo);

    enum ClipRoles {
        ClipName = Qt::UserRole + 1,
        ClipDuration
    };

private:
    Demo *demo;

};

#endif // CLIPLISTMODEL_H
