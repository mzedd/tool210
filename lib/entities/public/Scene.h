#ifndef SCENE_H
#define SCENE_H

#include <string>

class Scene
{
public:
    virtual ~Scene() { };

    std::string name() const { return name_; };
    void setName(std::string name) { name_ = name; };

protected:
    std::string name_;
};

#endif // SCENE_H
