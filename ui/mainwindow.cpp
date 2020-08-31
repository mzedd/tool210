#include "mainwindow.h"
#include <QDockWidget>
#include <QMenu>

#include "models/cliplistmodel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
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
    timelineView = new TimelineView(new ClipListModel(this), this);
    setCentralWidget(timelineView);

    QDockWidget *dockWidget = new QDockWidget(this);
    ClipScreenView *clipScreenView = new ClipScreenView(new OpenGLModel(this), this);
    dockWidget->setWidget(clipScreenView);

    addDockWidget(Qt::DockWidgetArea::TopDockWidgetArea, dockWidget);
}
