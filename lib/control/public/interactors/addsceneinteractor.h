#ifndef SCENEINFORMATIONINTERACTOR_H
#define SCENEINFORMATIONINTERACTOR_H

#include <string>
#include "Demo.h"
#include "renderer.h"

class AddSceneInteractor
{
public:
    AddSceneInteractor(Demo *demo, Renderer *renderer);
    void addScene();

private:
    Demo *demo;
    Renderer *renderer;
};

#endif // SCENEINFORMATIONINTERACTOR_H
