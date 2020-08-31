#include "openglscreen.h"
#include "demo/Demo.h"

OpenGLScreen::OpenGLScreen(QWidget* parent) :
    QOpenGLWidget(parent),
    clipToRender(nullptr),
    run(false)
{

}

OpenGLScreen::~OpenGLScreen()
{
    makeCurrent();
}

void OpenGLScreen::initializeGL()
{
    makeCurrent();
    initializeOpenGLFunctions();

    Demo::instance().initializeShaders(width(), height());
}

void OpenGLScreen::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    if(clipToRender) {
        clipToRender->getScene()->setViewportResolution(w, h);
    }
}

void OpenGLScreen::paintGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(clipToRender) {
        clipToRender->renderAt(time);
        glDrawArrays(GL_TRIANGLES, 0, 6);
    }

    if(run) {
        emit frameFinished();
        update();
    }
}

void OpenGLScreen::setTime(float time)
{
    this->time = time;
    update();
}

void OpenGLScreen::setClipToRender(int id)
{
    clipToRender = &Demo::instance().clipAt(id);
    update();
}

void OpenGLScreen::playPauseDemo()
{
    run = !run;
    update();
}
