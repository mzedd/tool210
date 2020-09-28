#ifndef SCENEINFORMATIONINTERACTOR_H
#define SCENEINFORMATIONINTERACTOR_H

#include <string>
#include "Demo.h"

class SceneInformationInteractor
{
public:
    SceneInformationInteractor(Demo *demo);

    std::string getShaderFilepathBy(int id);

private:
    Demo *demo;
};

#endif // SCENEINFORMATIONINTERACTOR_H
