#ifndef CLIPINSPECTORMODEL_H
#define CLIPINSPECTORMODEL_H

#include <vector>
#include <QObject>
#include "models/Clip.h"

class Q_DECL_EXPORT ClipInspectorModel : public QObject
{
    Q_OBJECT

public:
    explicit ClipInspectorModel(QObject *parent = nullptr);
    void setSceneList(std::vector<Scene*> *sceneList);

    Clip *selectedClip() const;
    void setSelectedClip(Clip *clip);

private:
    Clip *selectedClip_;
    std::vector<Scene*> *sceneList;

Q_SIGNALS:
    void selectedClipNameChanged();
    void selectedClipDurationChanged();

private Q_SLOTS:
    void setSelectedClipName(const QString& name);

};

#endif // CLIPINSPECTORMODEL_H
