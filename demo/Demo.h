#ifndef DEMO_H
#define DEMO_H

#include <vector>
#include "Clip.h"
#include "Scene.h"

class Demo
{
private:
    Demo();
    ~Demo();

    std::vector<Clip> clipList;
    std::vector<Scene*> sceneList;
    // TODO: musicTrack
    // TODO: postProcessingEffects

public:
    Demo(const Demo&) = delete;
    Demo(Demo&&) = delete;
    Demo& operator=(const Demo&) = delete;
    Demo& operator=(Demo&&) = delete;

    static Demo& instance();

    int clipCount() const;
    Clip& clipAt(int index);
    void addClip();
    bool swapClips(int first, int second);

    int sceneCount() const;
    Scene *sceneAt(int index);
    void addScene();
    void initializeShaders(int w, int h);
};

#endif // DEMO_H
