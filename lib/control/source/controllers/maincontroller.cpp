#include "maincontroller.h"

#include <QDebug>

MainController::MainController(QObject *parent) :
    QObject(parent),
    demo(nullptr),
    clipListModel(nullptr),
    sceneListModel(nullptr),
    addSceneInteractor(nullptr),
    renderContext(nullptr),
    demoFileAccessor(nullptr)
{
}

void MainController::setupConnections()
{
    connect(clipListModel, &ClipListModel::dataChanged, this, &MainController::modelDataChanged);
}

void MainController::setClipListModel(ClipListModel *clipListModel)
{
    this->clipListModel = clipListModel;
}

void MainController::setSceneListModel(SceneListModel *sceneListModel)
{
    this->sceneListModel = sceneListModel;
}

void MainController::setRenderer(Renderer *renderer)
{
    this->renderer = renderer;
}

void MainController::setAddSceneInteractor(AddSceneInteractor *addSceneInteractor)
{
    this->addSceneInteractor = addSceneInteractor;
}

void MainController::setRenderContext(RenderContext *renderContext)
{
    this->renderContext = renderContext;
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

    if(renderContext)
        renderContext->setDemo(demo);
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

    for(Scene *scene : demo->sceneList()) {
        renderer->addShader(scene->id(), scene->shaderFileName());
    }
}

void MainController::storeDemo(QString filename)
{
    if(demo) {
        demoFileAccessor->storeDemo(filename, demo);
    }
}

void MainController::modelDataChanged()
{
    renderer->renderAt(renderContext->time());
}
