#ifndef SHADERONLYSCENE_H
#define SHADERONLYSCENE_H

#include "Scene.h"
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>

class ShaderOnlyScene : public Scene, protected QOpenGLFunctions
{
private:
    QOpenGLShaderProgram shaderProgram;
    QOpenGLVertexArrayObject vao;
    QOpenGLBuffer vbo;
public:
    ShaderOnlyScene();
    ~ShaderOnlyScene();
    void initialize();
    void renderAt(float time);
    bool setShader(const QString& filename);
    void setViewportResolution(int w, int h);
};

#endif // SHADERONLYSCENE_H
