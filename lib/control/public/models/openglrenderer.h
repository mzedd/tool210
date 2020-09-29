#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H

#include <QObject>
#include <QOpenGLFunctions>
#include <QMap>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>

#include "Clip.h"
#include "renderer.h"

class OpenGLRenderer : public QObject, protected QOpenGLFunctions, public Renderer
{
public:
    explicit OpenGLRenderer(QObject *parent = nullptr);
    void initializeGL();

    // Renderer interface
    void setClipToRender(Clip *clip);
    void renderAt(float time);
    void setViewport(int width, int height);
    bool addShader(int id, std::string filepath);
    void removeShader(int id);

private:
    QMap<int, QOpenGLShaderProgram *> shaderMap;
    Clip *clipToRender;

    QOpenGLVertexArrayObject vao;
    QOpenGLBuffer vbo;

    int width;
    int height;
};

#endif // OPENGLRENDERER_H
