#ifndef CLIPLISTMODEL_H
#define CLIPLISTMODEL_H

#include <vector>
#include <QAbstractTableModel>

class Clip;

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

    void setClipList(std::vector<Clip *> *clipList);

    enum ClipRoles {
        ClipName = Qt::UserRole + 1,
        ClipDuration
    };

private:
    std::vector<Clip *> *clipList;

};

#endif // CLIPLISTMODEL_H
