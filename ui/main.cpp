#include <QApplication>

#include "mainwindow.h"
#include "models/Demo.h"
#include "models/cliplistmodel.h"
#include "models/openglmodel.h"
#include "models/clipinspectormodel.h"
#include "models/scenelistmodel.h"

#include "maincontroller.h"

int main(int argc, char *argv[])
{
    QApplication::setApplicationName("tool210");
    QApplication::setOrganizationName("Team 210");
    QApplication app(argc, argv);

    MainWindow mainWindow;
    MainController mainController;
    mainWindow.setMainController(&mainController);

    Demo demo;
    mainController.setModel(&demo);

    ClipListModel *clipListModel = new ClipListModel;
    clipListModel->setClipList(&demo.clipList());
    mainController.timelineController()->setModel(clipListModel);
    mainWindow.setClipListModel(clipListModel);

    OpenGLModel *openGLModel = new OpenGLModel;
    openGLModel->setSceneList(&demo.sceneList());
    mainController.clipsScreenController()->setModel(openGLModel);
    mainWindow.setOpenGLModel(openGLModel);

    ClipInspectorModel *clipInspectorModel = new ClipInspectorModel;
    SceneListModel *sceneListModel = new SceneListModel;
    sceneListModel->setSceneList(&demo.sceneList());
    clipInspectorModel->setSceneListModel(sceneListModel);
    mainController.clipInspectorController()->setModel(clipInspectorModel);
    mainWindow.setClipInspectorModel(clipInspectorModel);

    mainWindow.initialize();
    mainWindow.show();

    return app.exec();
}
