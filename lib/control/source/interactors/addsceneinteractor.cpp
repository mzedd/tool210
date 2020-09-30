#include "interactors/addsceneinteractor.h"

AddSceneInteractor::AddSceneInteractor(Demo *demo, Renderer *renderer):
    demo(demo),
    renderer(renderer)
{

}

void AddSceneInteractor::addScene()
{
    demo->addScene();
    Scene *scene = demo->sceneList().back();
    renderer->addShader(scene->id(), scene->shaderFileName());
}
