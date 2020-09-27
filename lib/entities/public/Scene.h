#ifndef SCENE_H
#define SCENE_H

#include <string>

class Scene
{
public:
    Scene(int id) : id_(id) {};
    virtual ~Scene() { };

    int id() const { return id_;}

    std::string name() const { return name_; };
    void setName(std::string name) { name_ = name; };

    virtual std::string shaderFileName() const = 0;

protected:
    int id_;
    std::string name_;
};

#endif // SCENE_H
