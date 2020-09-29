#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H

#include <QObject>
#include <QElapsedTimer>
#include <QOpenGLFunctions>
#include <vector>
#include <QMap>
#include <QOpenGLShaderProgram>
#include "Clip.h"
#include "interactors/sceneinformationinteractor.h"
#include "rendercontext.h"
#include "renderer.h"

class Q_DECL_EXPORT OpenGLRenderer : public QObject, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit OpenGLRenderer(QObject *parent = nullptr);

    void setSceneInformationInteractor(SceneInformationInteractor* interactor);

    Clip *clipToRender() const;
    void setClipToRender(Clip *clip);

    void initializeGL();
    void resiszeGL(int w, int h);
    void paintGL();

    void setSceneList(std::vector<Scene*> *sceneList);

private:
    Clip *clipToRender_;

    std::vector<Scene*> *sceneList;
    int width;
    int height;

    QMap<int, QOpenGLShaderProgram *> shaderMap;

    SceneInformationInteractor *sceneInformationInteractor;

Q_SIGNALS:
    void timeChanged();
    void clipToRenderChanged();
    void runChanged();
};

#endif // OPENGLRENDERER_H
