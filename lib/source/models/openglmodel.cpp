#include "openglmodel.h"
#include "models/Demo.h"
#include "models/Scene.h"

constexpr float MSEC_PER_SECS = 0.001f;

OpenGLModel::OpenGLModel(QObject *parent) :
    QObject(parent),
    time_(10.0f),
    clipToRender_(nullptr),
    run_(false),
    timeAtRunChanged(0.0f)
{
    timer.start();
}

float OpenGLModel::time() const
{
    return time_;
}

void OpenGLModel::setTime(float time)
{
    this->time_ = time;
    timeAtRunChanged = timer.elapsed() * MSEC_PER_SECS - time_;
}

Clip *OpenGLModel::clipToRender() const
{
    return clipToRender_;
}

void OpenGLModel::setClipToRender(Clip *clip)
{
    clipToRender_ = clip;
    emit clipToRenderChanged();
}

bool OpenGLModel::run() const
{
    return run_;
}

void OpenGLModel::setRun(bool run)
{
    run_ = run;
    timeAtRunChanged = timer.elapsed() * MSEC_PER_SECS - time_;
}

void OpenGLModel::initializeGL()
{
    initializeOpenGLFunctions();
}

void OpenGLModel::resiszeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    for(unsigned int i = 0; i < sceneList->size(); i++) {
        sceneList->at(i)->setViewportResolution(w, h);
    }
}

void OpenGLModel::paintGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(clipToRender()) {
        if(!clipToRender()->getScene()->isInitialized()) {
            clipToRender()->getScene()->initialize();
        }

        clipToRender()->renderAt(time());
        glDrawArrays(GL_TRIANGLES, 0, 6);
    }
}

float OpenGLModel::deltaTime()
{
    time_ = timer.elapsed() * MSEC_PER_SECS - timeAtRunChanged;
    return time_;
}

void OpenGLModel::setSceneList(std::vector<Scene *> *sceneList)
{
    this->sceneList = sceneList;
}
