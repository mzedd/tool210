#include "openglmodel.h"
#include "Demo.h"
#include "Scene.h"



OpenGLModel::OpenGLModel(QObject *parent) :
    QObject(parent),
    clipToRender_(nullptr),
    sceneInformationInteractor(nullptr)
{
}

void OpenGLModel::setSceneInformationInteractor(SceneInformationInteractor *sceneInformationInteractor)
{
    this->sceneInformationInteractor = sceneInformationInteractor;
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

void OpenGLModel::initializeGL()
{
    initializeOpenGLFunctions();
}

void OpenGLModel::resiszeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    for(unsigned int i = 0; i < sceneList->size(); i++) {
        //sceneList->at(i)->setViewportResolution(w, h);
    }

    width = w;
    height = h;
}

void OpenGLModel::paintGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(clipToRender()) {
        /*if(!clipToRender()->scene()->isInitialized()) {
            clipToRender()->scene()->initialize();
            clipToRender()->scene()->setViewportResolution(width, height);
        }

        clipToRender()->renderAt(time());*/
        glDrawArrays(GL_TRIANGLES, 0, 6);
    }
}

void OpenGLModel::setSceneList(std::vector<Scene *> *sceneList)
{
    this->sceneList = sceneList;
}
