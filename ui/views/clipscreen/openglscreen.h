#ifndef OPENGLSCREEN_H
#define OPENGLSCREEN_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include "models/openglrenderer.h"
#include "controllers/renderer.h"

class RenderContext;

class OpenGLScreen : public QOpenGLWidget, protected QOpenGLFunctions, public Renderer
{
    Q_OBJECT
public:
    OpenGLScreen(QWidget* parent = nullptr);
    ~OpenGLScreen();

    void setRenderContext(RenderContext *renderContext);

    // Renderer interface
    void setClipToRender(Clip *clip) override;
    void renderAt(float time) override;
    void setViewport(int width, int height) override;
    bool addShader(int id, std::string filepath) override;
    void removeShader(int id) override;

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    QMap<int, QOpenGLShaderProgram *> shaderMap;
    Clip *clipToRender;

    RenderContext *renderContext;

    QOpenGLVertexArrayObject vao;
    QOpenGLBuffer vbo;

    int width;
    int height;

Q_SIGNALS:
    void frameFinishedAt(float time);

};

#endif // OPENGLSCREEN_H
