#ifndef DEMOFILEACCESSINTERFACE_H
#define DEMOFILEACCESSINTERFACE_H

#include <vector>
#include "models/Clip.h"
#include "models/Scene.h"

class DemoFileAccessInterface {
public:
    virtual QString getDemoName() = 0;
    virtual std::vector<Clip *> getClipList() = 0;
    virtual std::vector<Scene *> getSceneList() = 0;
};

#endif // DEMOFILEACCESSINTERFACE_H
