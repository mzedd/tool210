#ifndef CLIP_H
#define CLIP_H

#include <QString>
#include "Scene.h"

class Clip
{
public:
    Clip();
    void renderAt(float time);

private:
    QString name;
    float duration;
    Scene *scene;
};

#endif // CLIP_H
