#ifndef SCENEINFORMATIONINTERACTOR_H
#define SCENEINFORMATIONINTERACTOR_H

#include <string>
#include "Demo.h"
#include "renderer.h"

class AddSceneInteractor
{
public:
    AddSceneInteractor(Renderer *renderer);
    void setDemo(Tool210::Entities::Demo *demo);
    void addScene();
    void setSceneShaderFilename(int id, std::string filename);
    void addShader(int id, std::string filepath);

    std::string demoFilePath() const;
    void setDemoFilePath(const std::string filepath);

private:
    Tool210::Entities::Demo *demo;
    Renderer *renderer;

    std::string demoFilePath_;
};

#endif // SCENEINFORMATIONINTERACTOR_H
