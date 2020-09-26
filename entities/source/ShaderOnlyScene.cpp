#include "ShaderOnlyScene.h"

ShaderOnlyScene::ShaderOnlyScene()
{
    name_ = std::string("default shader only scene");
    shaderFileName_ = std::string("");
}

ShaderOnlyScene::~ShaderOnlyScene()
{

}

std::string ShaderOnlyScene::shaderFileName() const
{
    return shaderFileName_;
}

void ShaderOnlyScene::setShaderFileName(std::string filename)
{
    shaderFileName_ = filename;
}
