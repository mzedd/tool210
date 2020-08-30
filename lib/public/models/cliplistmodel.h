#ifndef CLIPLISTMODEL_H
#define CLIPLISTMODEL_H

#include <QAbstractListModel>

class Q_DECL_EXPORT ClipListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    ClipListModel(QObject *parent  = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool moveRows(const QModelIndex &sourceParent, int sourceRow, int count, const QModelIndex &destinationParent, int destinationChild) override;

    enum ClipRoles {
        ClipName = Qt::UserRole + 1,
        ClipDuration
    };

};

#endif // CLIPLISTMODEL_H
