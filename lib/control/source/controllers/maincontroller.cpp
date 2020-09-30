#include "maincontroller.h"

#include <QDebug>

MainController::MainController(QObject *parent) :
    QObject(parent),
    demo(nullptr),
    clipListModel(nullptr),
    sceneListModel(nullptr),
    addSceneInteractor(nullptr),
    demoFileAccessor(nullptr)
{
}

void MainController::setClipListModel(ClipListModel *clipListModel)
{
    this->clipListModel = clipListModel;
}

void MainController::setSceneListModel(SceneListModel *sceneListModel)
{
    this->sceneListModel = sceneListModel;
}

void MainController::setAddSceneInteractor(AddSceneInteractor *addSceneInteractor)
{
    this->addSceneInteractor = addSceneInteractor;
}

void MainController::setDemoFileAccessor(DemoFileAccessInterface *demoFileAccessor)
{
    this->demoFileAccessor = demoFileAccessor;
}

void MainController::distributeDemo()
{
    distributeDemoToModels();
    distributeDemoToInteractors();
}

void MainController::distributeDemoToModels()
{
    if(clipListModel)
        clipListModel->setDemo(demo);

    if(sceneListModel)
        sceneListModel->setSceneList(&demo->sceneList());
}

void MainController::distributeDemoToInteractors()
{
    if(addSceneInteractor)
        addSceneInteractor->setDemo(demo);
}

void MainController::newDemo()
{
    if(demo)
        delete demo;

    demo = new Demo;
    distributeDemo();
}

void MainController::loadDemo(QString filename)
{
    if(demo)
        delete demo;

    demo = demoFileAccessor->getDemo(filename);
    distributeDemo();
}

void MainController::storeDemo(QString filename)
{
    if(demo) {
        demoFileAccessor->storeDemo(filename, demo);
    }
}
