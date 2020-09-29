#include <QApplication>

#include "mainwindow.h"
#include "Demo.h"
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

    DemoJsonFileAccess *demoFileAccessor = new DemoJsonFileAccess;
    Demo *demo = demoFileAccessor->getDemo("resources/demo.json");

    RenderContext *renderContext = new RenderContext;

    ClipListModel *clipListModel = new ClipListModel;
    clipListModel->setDemo(demo);

    SceneListModel *sceneListModel = new SceneListModel;
    sceneListModel->setSceneList(&demo->sceneList());

    OpenGLRenderer *openGLRenderer = new OpenGLRenderer;

    mainWindow.setClipListModel(clipListModel);
    mainWindow.setSceneListModel(sceneListModel);
    mainWindow.setOpenGLModel(openGLRenderer);
    mainWindow.setRenderContext(renderContext);

    mainWindow.initialize();
    mainWindow.show();

    return app.exec();
}
