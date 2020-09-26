#ifndef SHADERONLYSCENE_H
#define SHADERONLYSCENE_H

#include "Scene.h"
#include <string>

class ShaderOnlyScene : public Scene
{
public:
    ShaderOnlyScene();
    ~ShaderOnlyScene();

    std::string shaderFileName() const;
    void setShaderFileName(std::string filename);

private:
    std::string shaderFileName_;
};

#endif // SHADERONLYSCENE_H
