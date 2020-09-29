#include "openglscreen.h"
#include <QtDebug>
#include "rendercontext.h"

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
    model->setViewport(w, h);
}

void OpenGLScreen::paintGL()
{
    model->renderAt(renderContext->time());

    if(renderContext->run()) {
        emit frameFinishedAt(renderContext->deltaTime());
        update();
    }
}
