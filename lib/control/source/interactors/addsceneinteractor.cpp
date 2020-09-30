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
    Scene *scene = demo->sceneList().back();
    renderer->addShader(scene->id(), scene->shaderFileName());
}
