#ifndef CLIPINSPECTORMODEL_H
#define CLIPINSPECTORMODEL_H

#include <vector>
#include <QObject>
#include "models/Clip.h"

class Q_DECL_EXPORT ClipInspectorModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Clip* selectedClip READ selectedClip WRITE setSelectedClip NOTIFY selectedClipChanged)

public:
    explicit ClipInspectorModel(QObject *parent = nullptr);
    void setSceneList(std::vector<Scene*> *sceneList);

    Clip *selectedClip() const;
    void setSelectedClip(Clip *clip);

private:
    Clip *selectedClip_;
    std::vector<Scene*> *sceneList;

Q_SIGNALS:
    void selectedClipChanged();
    void sceneListChanged();

};

#endif // CLIPINSPECTORMODEL_H
