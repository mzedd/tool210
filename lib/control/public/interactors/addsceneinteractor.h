#ifndef SCENEINFORMATIONINTERACTOR_H
#define SCENEINFORMATIONINTERACTOR_H

#include <string>
#include "Demo.h"
#include "renderer.h"

class AddSceneInteractor
{
public:
    AddSceneInteractor(Renderer *renderer);
    void setDemo(Demo *demo);
    void addScene();
    void setSceneShaderFilename(int id, std::string filename);

private:
    Demo *demo;
    Renderer *renderer;
};

#endif // SCENEINFORMATIONINTERACTOR_H
