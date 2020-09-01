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

    std::vector<Clip> *clipList();

    void addClip();
    void checkClipToBeRenderdChangedAt(float time);

    int sceneCount() const;
    Scene *sceneAt(int index);
    void addScene();
    void initializeShaders(int w, int h);

private:
    std::vector<Clip> clipList_;
    std::vector<Scene*> sceneList_;
    // TODO: musicTrack
    // TODO: postProcessingEffects

    int clipIdAt(float time);

Q_SIGNALS:
    void clipCreated(int id);
    void clipToRenderChanged(int id);

private Q_SLOTS:

};

#endif // DEMO_H
