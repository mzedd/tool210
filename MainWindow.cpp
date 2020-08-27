#include "MainWindow.h"
#include <QDockWidget>
#include "modules/ClipScreen/ClipScreen.h"
#include "modules/Timeline/Timeline.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QDockWidget *widget = new QDockWidget(QString("Screen"), this);
    widget->setWidget(new ClipScreen(this));
    addDockWidget(Qt::DockWidgetArea::TopDockWidgetArea, widget);

    widget = new QDockWidget("Timeline", this);
    widget->setWidget(new Timeline(this));
    addDockWidget(Qt::DockWidgetArea::BottomDockWidgetArea, widget);
}
