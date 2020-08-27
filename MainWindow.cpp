#include "MainWindow.h"
#include <QDockWidget>
#include "modules/ClipScreen/ClipScreen.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QDockWidget *widget = new QDockWidget(QString("Screen"), this);
    widget->setWidget(new ClipScreen);
    addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, widget);

    show();
}
