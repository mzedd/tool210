#include "MainWindow.h"
#include <QDockWidget>
#include <QMenu>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createMenu();
    createInitialWidgets();
    setupConnections();
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

void MainWindow::createInitialWidgets()
{
    clipScreen = new ClipScreen(this);
    QDockWidget *widget = new QDockWidget(QString("Screen"), this);
    widget->setWidget(clipScreen);
    addDockWidget(Qt::DockWidgetArea::TopDockWidgetArea, widget);

    timeline = new Timeline(this);
    widget = new QDockWidget("Timeline", this);
    widget->setWidget(timeline);
    addDockWidget(Qt::DockWidgetArea::BottomDockWidgetArea, widget);
}

void MainWindow::setupConnections()
{
    connect(timeline, SIGNAL(timeChanged(float)), clipScreen->getOpenGLScreen(), SLOT(setTime(float)));
    connect(timeline, SIGNAL(clipToRenderChanged(int)), clipScreen->getOpenGLScreen(), SLOT(setClipToRender(int)));
}
