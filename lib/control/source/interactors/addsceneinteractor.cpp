#include "interactors/addsceneinteractor.h"

#include <QDir>
#include <QFileInfo>
#include <QDebug>

AddSceneInteractor::AddSceneInteractor(Renderer *renderer):
    demo(nullptr),
    renderer(renderer),
    demoFilePath_("")
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

    QString demoPath = QFileInfo(QString::fromStdString(demoFilePath_)).path();
    std::string relativFilepath = QDir(demoPath).relativeFilePath(QString::fromStdString(filename)).toStdString();
    QString pathToShader = QDir(demoPath).absoluteFilePath(QString::fromStdString(relativFilepath));

    scene->setShaderFileName(relativFilepath);
    renderer->removeShader(id);
    renderer->addShader(scene->id(), pathToShader.toStdString());
}

void AddSceneInteractor::addShader(int id, std::string filepath)
{
    Scene *scene = demo->sceneAt(id);

    QString demoPath = QFileInfo(QString::fromStdString(demoFilePath_)).path();
    std::string relativFilepath = filepath;
    QString pathToShader = QDir(demoPath).absoluteFilePath(QString::fromStdString(relativFilepath));

    scene->setShaderFileName(relativFilepath);
    renderer->removeShader(id);
    renderer->addShader(scene->id(), pathToShader.toStdString());
}

std::string AddSceneInteractor::demoFilePath() const
{
    return demoFilePath_;
}

void AddSceneInteractor::setDemoFilePath(const std::string filepath)
{
    demoFilePath_ = filepath;
}
