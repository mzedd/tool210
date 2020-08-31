#include "openglscreen.h"

OpenGLScreen::OpenGLScreen(OpenGLModel *model, QWidget* parent) :
    QOpenGLWidget(parent),
    model(model)
{

}

OpenGLScreen::~OpenGLScreen()
{
    makeCurrent();
}

void OpenGLScreen::initializeGL()
{
    makeCurrent();
    model->initializeGL();
}

void OpenGLScreen::resizeGL(int w, int h)
{
    model->resiszeGL(w, h);
}

void OpenGLScreen::paintGL()
{
    model->paintGL();
}
