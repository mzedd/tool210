#include <QApplication>

#include "mainwindow.h"
#include "Demo.h"
#include "models/demomodel.h"
#include "models/cliplistmodel.h"
#include "models/openglmodel.h"
#include "models/clipinspectormodel.h"
#include "models/scenelistmodel.h"
#include "rendercontext.h"

#include "demojsonfileaccess.h"

int main(int argc, char *argv[])
{
    QApplication::setApplicationName("tool210");
    QApplication::setOrganizationName("Team 210");
    QApplication app(argc, argv);

    MainWindow mainWindow;

    DemoJsonFileAccess *demoFileAccessor = new DemoJsonFileAccess;

    Demo *demo = demoFileAccessor->getDemo("resources/demo.json");

    RenderContext *renderContext = new RenderContext;

    ClipListModel *clipListModel = new ClipListModel;
    clipListModel->setDemo(demo);
    mainWindow.setClipListModel(clipListModel);

    OpenGLModel *openGLModel = new OpenGLModel;
    openGLModel->setSceneList(&demo->sceneList());
    mainWindow.setOpenGLModel(openGLModel);

    ClipInspectorModel *clipInspectorModel = new ClipInspectorModel;
    SceneListModel *sceneListModel = new SceneListModel;
    sceneListModel->setSceneList(&demo->sceneList());
    clipInspectorModel->setClipListModel(clipListModel);
    clipInspectorModel->setSceneListModel(sceneListModel);
    mainWindow.setClipInspectorModel(clipInspectorModel);

    mainWindow.setRenderContext(renderContext);
    mainWindow.initialize();
    mainWindow.show();

    return app.exec();
}
