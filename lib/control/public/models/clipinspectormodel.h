#ifndef CLIPINSPECTORMODEL_H
#define CLIPINSPECTORMODEL_H

#include <vector>
#include <QObject>
#include "Clip.h"
#include "cliplistmodel.h"
#include "models/scenelistmodel.h"

class Q_DECL_EXPORT ClipInspectorModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Clip* selectedClip READ selectedClip WRITE setSelectedClip NOTIFY selectedClipChanged)

public:
    explicit ClipInspectorModel(QObject *parent = nullptr);
    void setSceneList(std::vector<Scene*> *sceneList);

    Clip *selectedClip() const;
    void setSelectedClip(Clip *clip);

    ClipListModel *clipList() const;
    void setClipListModel(ClipListModel *model);

    SceneListModel *sceneList() const;
    void setSceneListModel(SceneListModel *model);

private:
    Clip *selectedClip_;
    ClipListModel *clipList_;
    SceneListModel *sceneList_;

Q_SIGNALS:
    void selectedClipChanged();
    void sceneListChanged();

};

#endif // CLIPINSPECTORMODEL_H
