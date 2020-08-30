#include "mainwindow.h"
#include <QDockWidget>
#include <QMenu>

#include "models/cliplistmodel.h"
#include "views/clipscreenview.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      clipListView(new ClipListView(this))
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
    clipListView->setModel(new ClipListModel(this));
    setCentralWidget(clipListView);

    QDockWidget *dockWidget = new QDockWidget(this);
    ClipScreenView *clipScreenView = new ClipScreenView(this);
    dockWidget->setWidget(clipScreenView);

    addDockWidget(Qt::DockWidgetArea::TopDockWidgetArea, dockWidget);
}
