#include <QApplication>

#include "mainwindow.h"
#include "Demo.h"
#include "models/demomodel.h"
#include "models/cliplistmodel.h"
#include "models/openglmodel.h"
#include "models/clipinspectormodel.h"
#include "models/scenelistmodel.h"
#include "rendercontext.h"

#include "maincontroller.h"

#include "demojsonfileaccess.h"

int main(int argc, char *argv[])
{
    QApplication::setApplicationName("tool210");
    QApplication::setOrganizationName("Team 210");
    QApplication app(argc, argv);

    MainWindow mainWindow;
    MainController mainController;
    mainWindow.setMainController(&mainController);

    DemoJsonFileAccess *demoFileAccessor = new DemoJsonFileAccess;

    DemoModel *demoModel = new DemoModel;

    Demo *demo = demoFileAccessor->getDemo("resources/demo.json");
    mainController.setModel(demoModel);
    mainController.setDemoFileAccessor(demoFileAccessor);

    RenderContext *renderContext = new RenderContext;

    ClipListModel *clipListModel = new ClipListModel;
    clipListModel->setClipList(&demo->clipList());
    mainController.timelineController()->setModel(clipListModel);
    mainWindow.setClipListModel(clipListModel);

    OpenGLModel *openGLModel = new OpenGLModel;
    openGLModel->setSceneList(&demo->sceneList());
    mainController.clipsScreenController()->setModel(openGLModel);
    mainWindow.setOpenGLModel(openGLModel);

    ClipInspectorModel *clipInspectorModel = new ClipInspectorModel;
    SceneListModel *sceneListModel = new SceneListModel;
    sceneListModel->setSceneList(&demo->sceneList());
    clipInspectorModel->setClipListModel(clipListModel);
    clipInspectorModel->setSceneListModel(sceneListModel);
    mainController.clipInspectorController()->setModel(clipInspectorModel);
    mainWindow.setClipInspectorModel(clipInspectorModel);

    mainWindow.setRenderContext(renderContext);
    mainWindow.initialize();
    mainWindow.show();

    return app.exec();
}
