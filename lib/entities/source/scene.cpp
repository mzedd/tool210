#include "Scene.h"

static int idCounter = 0;

Scene::Scene() :
    id_(idCounter++),
    name_(std::string("default shader only scene")),
    shaderFileName_(std::string(""))
{

}

int Scene::id() const
{
    return id_;
}

std::string Scene::name() const
{
    return name_;
};

void Scene::setName(std::string name)
{
    name_ = name;
};

std::string Scene::shaderFileName() const
{
    return shaderFileName_;
}

void Scene::setShaderFileName(std::string filename)
{
    shaderFileName_ = filename;
}
