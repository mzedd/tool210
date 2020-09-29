#include "openglscreen.h"
#include <QtDebug>

OpenGLScreen::OpenGLScreen(OpenGLRenderer *model, QWidget* parent) :
    QOpenGLWidget(parent),
    model(model)
{

}

OpenGLScreen::~OpenGLScreen()
{
    makeCurrent();
}

void OpenGLScreen::setRenderContext(RenderContext *renderContext)
{
    this->renderContext = renderContext;
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

    if(renderContext->run()) {
        emit frameFinishedAt(renderContext->deltaTime());
        update();
    }
}
