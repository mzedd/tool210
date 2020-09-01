#ifndef CLIP_H
#define CLIP_H

#include <QString>
#include "Scene.h"

class Clip
{
public:
    Clip();
    void renderAt(float time);
    QString getName();
    void setName(QString name);
    float getDuration();
    void setDuration(float duration);
    Scene *getScene();
    void setScene(Scene *scene);

private:
    QString name;
    float duration;
    Scene *scene;
};

#endif // CLIP_H
