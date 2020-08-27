#ifndef SCENE_H
#define SCENE_H

class Scene
{
public:
    virtual ~Scene();
    virtual void renderAt(float time);
};

#endif // SCENE_H
