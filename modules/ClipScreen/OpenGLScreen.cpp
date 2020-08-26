#include "OpenGLScreen.h"

OpenGLScreen::OpenGLScreen(QWidget* parent) :
    QOpenGLWidget(parent)
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
}

void OpenGLScreen::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void OpenGLScreen::paintGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
