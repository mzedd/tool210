#ifndef SCENE_H
#define SCENE_H

#include <QString>

class Scene
{
public:
    virtual ~Scene() { };
    virtual void renderAt(float time) = 0;

protected:
    QString name;
};

#endif // SCENE_H
