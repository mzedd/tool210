#include "interactors/addsceneinteractor.h"

AddSceneInteractor::AddSceneInteractor(Renderer *renderer):
    demo(nullptr),
    renderer(renderer)
{

}

void AddSceneInteractor::setDemo(Demo *demo)
{
    this->demo = demo;
}

void AddSceneInteractor::addScene()
{
    demo->addScene();
}

void AddSceneInteractor::setSceneShaderFilename(int id, std::string filename)
{
    Scene *scene = demo->sceneAt(id);
    scene->setShaderFileName(filename);
    renderer->addShader(scene->id(), filename);
}
