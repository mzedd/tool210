#ifndef SCENE_H
#define SCENE_H

#include <QString>

class Scene
{
public:
    virtual ~Scene() { };
    virtual void initialize() = 0;
    virtual void renderAt(float time) = 0;
    virtual void setViewportResolution(int w, int h) = 0;

protected:
    QString name;
};

#endif // SCENE_H
