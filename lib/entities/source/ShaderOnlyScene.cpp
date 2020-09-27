#include "ShaderOnlyScene.h"

static int idCounter = 0;

ShaderOnlyScene::ShaderOnlyScene() :
    Scene(idCounter++)
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
