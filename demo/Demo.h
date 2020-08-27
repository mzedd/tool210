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
};

#endif // DEMO_H
