#include "openglmodel.h"
#include "models/Demo.h"
#include "models/Scene.h"

OpenGLModel::OpenGLModel(QObject *parent) :
    QObject(parent),
    time(10.0f),
    clipToRender(nullptr),
    run(false)
{

}

void OpenGLModel::initializeGL()
{
    initializeOpenGLFunctions();
}

void OpenGLModel::resiszeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    if(clipToRender) {
        Scene* scene = clipToRender->getScene();

        if(scene) {
            scene->setViewportResolution(w, h);
            emit frameFinished();
        }
    }
}

void OpenGLModel::paintGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(clipToRender) {
        clipToRender->renderAt(time);
        glDrawArrays(GL_TRIANGLES, 0, 6);
    }

    if(run) {
        emit frameFinished();
    }
}


void OpenGLModel::setTime(float time)
{
    this->time = time;
}

void OpenGLModel::setClipToRender(int /*id*/)
{

}

void OpenGLModel::playPauseDemo()
{
    run = !run;
}
