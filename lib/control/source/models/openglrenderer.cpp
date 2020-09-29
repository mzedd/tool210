#include "openglrenderer.h"
#include "Demo.h"
#include "Scene.h"

OpenGLRenderer::OpenGLRenderer(QObject *parent) :
    QObject(parent),
    clipToRender_(nullptr),
    sceneInformationInteractor(nullptr)
{
}

void OpenGLRenderer::setSceneInformationInteractor(SceneInformationInteractor *sceneInformationInteractor)
{
    this->sceneInformationInteractor = sceneInformationInteractor;
}

Clip *OpenGLRenderer::clipToRender() const
{
    return clipToRender_;
}

void OpenGLRenderer::setClipToRender(Clip *clip)
{
    clipToRender_ = clip;
    emit clipToRenderChanged();
}

void OpenGLRenderer::initializeGL()
{
    initializeOpenGLFunctions();
}

void OpenGLRenderer::resiszeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    for(unsigned int i = 0; i < sceneList->size(); i++) {
        //sceneList->at(i)->setViewportResolution(w, h);
    }

    width = w;
    height = h;
}

void OpenGLRenderer::paintGL()
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

void OpenGLRenderer::setSceneList(std::vector<Scene *> *sceneList)
{
    this->sceneList = sceneList;
}
