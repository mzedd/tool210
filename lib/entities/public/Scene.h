#ifndef SCENE_H
#define SCENE_H

#include <string>

class Scene
{
public:
    Scene();

    int id() const;

    std::string name() const;
    void setName(std::string name);

    std::string shaderFileName() const;
    void setShaderFileName(std::string filename);

protected:
    int id_;
    std::string name_;
    std::string shaderFileName_;
};

#endif // SCENE_H
