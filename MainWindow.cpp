#include "MainWindow.h"
#include <QDockWidget>
#include <QMenu>
#include "modules/ClipScreen/ClipScreen.h"
#include "modules/Timeline/Timeline.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createMenu();
    createInitialWidgets();
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
    QDockWidget *widget = new QDockWidget(QString("Screen"), this);
    widget->setWidget(new ClipScreen(this));
    addDockWidget(Qt::DockWidgetArea::TopDockWidgetArea, widget);

    widget = new QDockWidget("Timeline", this);
    widget->setWidget(new Timeline(this));
    addDockWidget(Qt::DockWidgetArea::BottomDockWidgetArea, widget);
}
