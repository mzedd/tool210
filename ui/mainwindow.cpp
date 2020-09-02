#include "mainwindow.h"
#include <QDockWidget>
#include <QMenu>

#include "models/cliplistmodel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      mainController(nullptr)
{

}

void MainWindow::setMainController(MainController *mainController)
{
    this->mainController = mainController;
}

void MainWindow::setClipListModel(ClipListModel *clipListModel)
{
    timelineView = new TimelineView(clipListModel, this);
    timelineView->setController(mainController->timelineController());
}

void MainWindow::setOpenGLModel(OpenGLModel *openGLmodel)
{
    clipScreenView = new ClipScreenView(openGLmodel, this);
    clipScreenView->setController(mainController->clipsScreenController());
}

void MainWindow::setClipInspectorModel()
{
    clipInspectorView = new ClipInspectorView(this);
}

void MainWindow::initialize()
{
    createMenu();
    createWidgets();
}

void MainWindow::createMenu()
{
    QMenuBar *menuBar = new QMenuBar(this);
    QMenu *fileMenu = new QMenu("File", menuBar);
    QMenu *editMenu = new QMenu("Edit", menuBar);
    QMenu *viewMenu = new QMenu("View", menuBar);

    menuBar->addMenu(fileMenu);
    menuBar->addMenu(editMenu);
    menuBar->addMenu(viewMenu);

    setMenuBar(menuBar);
}

void MainWindow::createWidgets()
{
    setCentralWidget(clipScreenView);

    QDockWidget *dockWidget = new QDockWidget(this);
    dockWidget->setFeatures(QDockWidget::DockWidgetMovable);
    dockWidget->setWidget(timelineView);
    addDockWidget(Qt::DockWidgetArea::BottomDockWidgetArea, dockWidget);

    dockWidget = new QDockWidget(this);
    dockWidget->setFeatures(QDockWidget::DockWidgetMovable);
    dockWidget->setWidget(clipInspectorView);
    addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea, dockWidget);
}
