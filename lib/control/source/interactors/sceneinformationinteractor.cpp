#include "interactors/sceneinformationinteractor.h"

SceneInformationInteractor::SceneInformationInteractor(Demo *demo):
    demo(demo)
{

}

std::string SceneInformationInteractor::getShaderFilepathBy(int id)
{
    Scene *scene = demo->sceneAt(id);
    return scene->shaderFileName();
}
