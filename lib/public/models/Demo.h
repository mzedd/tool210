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
    Demo(const Demo&) = delete;
    Demo(Demo&&) = delete;
    Demo& operator=(const Demo&) = delete;
    Demo& operator=(Demo&&) = delete;

    std::vector<Clip> *clipList();

    void addClip();

    int sceneCount() const;
    Scene *sceneAt(int index);
    void addScene();
    void initializeShaders(int w, int h);

private:
    std::vector<Clip> clipList_;
    std::vector<Scene*> sceneList_;
    // TODO: musicTrack
    // TODO: postProcessingEffects

Q_SIGNALS:
    void clipCreated(int id);
};

#endif // DEMO_H
