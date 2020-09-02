#include "openglscreen.h"
#include <QtDebug>
#include "models/ShaderOnlyScene.h"

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
    model->initializeGL();
}

void OpenGLScreen::resizeGL(int w, int h)
{
    model->resiszeGL(w, h);
}

void OpenGLScreen::paintGL()
{
    model->paintGL();

    if(model->run())
        emit frameFinishedAt(model->deltaTime());
        update();
}
