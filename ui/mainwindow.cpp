#include "mainwindow.h"
#include <QDockWidget>
#include <QMenu>
#include <QFileDialog>

#include "models/cliplistmodel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    clipInspectorView = new ClipInspectorView(this);
    sceneEditorView = new SceneEditorView(this);
}

void MainWindow::setMainController(MainController *mainController)
{
    this->mainController = mainController;
}

void MainWindow::setClipListModel(ClipListModel *clipListModel)
{
    timelineView = new TimelineView(clipListModel, this);
    clipInspectorView->setClipListModel(clipListModel);
}

void MainWindow::setSceneListModel(SceneListModel *sceneListModel)
{
    clipInspectorView->setSceneListModel(sceneListModel);
    sceneEditorView->setModel(sceneListModel);
}

void MainWindow::setOpenGLModel(OpenGLRenderer *openGLmodel)
{
    clipScreenView = new ClipScreenView(openGLmodel, this);
}

void MainWindow::setRenderContext(RenderContext *renderContext)
{
    timelineView->setRenderContext(renderContext);
    clipScreenView->setRenderContext(renderContext);
}

void MainWindow::initialize()
{
    createMenu();
    createWidgets();
    createConnections();
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

    QAction *newDemo = new QAction("New", menuBar);
    fileMenu->addAction(newDemo);
    connect(newDemo, &QAction::triggered, this, &MainWindow::handleNewDemo);

    QAction *loadDemo = new QAction("Open", menuBar);
    fileMenu->addAction(loadDemo);
    connect(loadDemo, &QAction::triggered, this, &MainWindow::handleLoadDemo);

    QAction *saveDemo = new QAction("Save", menuBar);
    fileMenu->addAction(saveDemo);
    connect(saveDemo, &QAction::triggered, this, &MainWindow::handelSaveDemo);

    QAction *closeTool210 = new QAction("Close", menuBar);
    fileMenu->addAction(closeTool210);
    connect(closeTool210, &QAction::triggered, QApplication::instance(), &QApplication::quit);

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

    dockWidget = new QDockWidget(this);
    dockWidget->setFeatures(QDockWidget::DockWidgetMovable);
    dockWidget->setWidget(sceneEditorView);
    addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea, dockWidget);
}

void MainWindow::createConnections()
{
    connect(timelineView->clipListView->selectionModel(), &QItemSelectionModel::currentChanged, clipInspectorView->dataMapper, &QDataWidgetMapper::setCurrentModelIndex);
}

void MainWindow::handleNewDemo()
{
    mainController->newDemo();
}

void MainWindow::handleLoadDemo()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Demo"), ".", tr("JSON files (*.json)"));
    mainController->loadDemo(filename);
}

void MainWindow::handelSaveDemo()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save Demo"), ".", tr("JSON files (*.json)"));
    mainController->storeDemo(filename);
}
