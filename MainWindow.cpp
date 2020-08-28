#include "MainWindow.h"
#include <QDockWidget>
#include <QMenu>

constexpr float MSECS_PER_SECS = 0.001f;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      startTime(0.0f)
{
    setFocusPolicy(Qt::FocusPolicy::StrongFocus);

    createMenu();
    createInitialWidgets();
    setupConnections();

    timer.start();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key::Key_Space) {
        startTime = timer.elapsed() * MSECS_PER_SECS;
        emit playPauseDemo();
    }

    QMainWindow::keyPressEvent(event);
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
    connect(timeline, SIGNAL(timeChanged(float)), this, SLOT(setTime(float)));
    connect(timeline, SIGNAL(clipToRenderChanged(int)), clipScreen->getOpenGLScreen(), SLOT(setClipToRender(int)));
    connect(this, SIGNAL(playPauseDemo()), clipScreen->getOpenGLScreen(), SLOT(playPauseDemo()));
    connect(clipScreen->getOpenGLScreen(), SIGNAL(frameFinished()), this, SLOT(frameFinished()));
    connect(this, SIGNAL(timeChanged(float)), timeline, SLOT(setTime(float)));
    connect(this, SIGNAL(timeChanged(float)), clipScreen->getOpenGLScreen(), SLOT(setTime(float)));
}

void MainWindow::frameFinished()
{
    emit timeChanged(timer.elapsed() * MSECS_PER_SECS - startTime + time);
}

void MainWindow::setTime(float time)
{
    startTime = timer.elapsed() * MSECS_PER_SECS;
    this->time = time;
}
