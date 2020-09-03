#ifndef DEMO_H
#define DEMO_H

#include <vector>
#include <QObject>
#include "Clip.h"
#include "Scene.h"

class Q_DECL_EXPORT Demo : public QObject
{
    Q_OBJECT

public:
    Demo();
    ~Demo();
    Q_DISABLE_COPY_MOVE(Demo)

    std::vector<Clip*> *clipList();
    std::vector<Scene*> *sceneList();

    void addClip();
    void checkClipToBeRenderdChangedAt(float time);

    int sceneCount() const;
    Scene *sceneAt(int index);
    void addScene();
    void initializeShaders(int w, int h);

    int selectedClip();
    void setSelectedClip(int id);

private:
    std::vector<Clip *> clipList_;
    std::vector<Scene *> sceneList_;

    int selectedClip_;
    // TODO: musicTrack
    // TODO: postProcessingEffects

    int clipIdAt(float time);

Q_SIGNALS:
    void clipToRenderChanged(int id);
    void selectedClipChanged(int id);

private Q_SLOTS:

};

#endif // DEMO_H
