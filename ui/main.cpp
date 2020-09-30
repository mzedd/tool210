#include <QApplication>

#include "mainwindow.h"
#include "controllers/maincontroller.h"
#include "interactors/addsceneinteractor.h"
#include "models/cliplistmodel.h"
#include "models/scenelistmodel.h"
#include "models/openglrenderer.h"
#include "rendercontext.h"

#include "demojsonfileaccess.h"

int main(int argc, char *argv[])
{
    QApplication::setApplicationName("tool210");
    QApplication::setOrganizationName("Team 210");
    QApplication app(argc, argv);

    MainWindow mainWindow;

    RenderContext *renderContext = new RenderContext;
    ClipListModel *clipListModel = new ClipListModel;
    SceneListModel *sceneListModel = new SceneListModel;
    OpenGLRenderer *openGLRenderer = new OpenGLRenderer;

    AddSceneInteractor *addSceneInteractor = new AddSceneInteractor(openGLRenderer);
    DemoJsonFileAccess *demoFileAccessor = new DemoJsonFileAccess;
    MainController mainController;

    mainController.setClipListModel(clipListModel);
    mainController.setSceneListModel(sceneListModel);
    mainController.setDemoFileAccessor(demoFileAccessor);
    mainController.setAddSceneInteractor(addSceneInteractor);

    mainWindow.setMainController(&mainController);
    mainWindow.setClipListModel(clipListModel);
    mainWindow.setSceneListModel(sceneListModel);
    mainWindow.setOpenGLModel(openGLRenderer);
    mainWindow.setRenderContext(renderContext);

    mainWindow.initialize();
    mainWindow.show();

    mainController.newDemo(); // initialize the editor with a fresh empty demo

    return app.exec();
}
