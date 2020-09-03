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
    virtual bool isInitialized() const = 0;

    QString name() const { return name_; };
    void setName(QString name) { name_ = name; };

protected:
    QString name_;
};

#endif // SCENE_H
