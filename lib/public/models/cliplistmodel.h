#ifndef CLIPLISTMODEL_H
#define CLIPLISTMODEL_H

#include <vector>
#include <QAbstractListModel>

class Clip;

class Q_DECL_EXPORT ClipListModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(Clip* selectedClip READ selectedClip NOTIFY selectedClipChanged)

public:
    ClipListModel(QObject *parent  = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool moveRows(const QModelIndex &sourceParent, int sourceRow, int count, const QModelIndex &destinationParent, int destinationChild) override;

    Clip *selectedClip() const;
    void setSelectedClip(int id);

    void setClipList(std::vector<Clip *> *clipList);

    enum ClipRoles {
        ClipName = Qt::UserRole + 1,
        ClipDuration
    };

private:
    std::vector<Clip *> *clipList;
    Clip *selectedClip_;

Q_SIGNALS:
    void selectedClipChanged(QModelIndex index);
    void selectedClipDurationChanged();
};

#endif // CLIPLISTMODEL_H
