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
    initializeOpenGLFunctions();
}

void OpenGLScreen::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    if(model->clipToRender())
        model->clipToRender()->getScene()->setViewportResolution(w, h);
}

void OpenGLScreen::paintGL()
{
    glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(model->clipToRender()) {
        if(!model->clipToRender()->getScene()->isInitialized()) {
            model->clipToRender()->getScene()->initialize();
        }

        model->clipToRender()->renderAt(10.0f);
        glDrawArrays(GL_TRIANGLES, 0, 6);
    }
}
