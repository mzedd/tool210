#ifndef SHADERONLYSCENE_H
#define SHADERONLYSCENE_H

#include "Scene.h"
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>

class ShaderOnlyScene : public Scene
{
private:
    QOpenGLShaderProgram shaderProgram;
    QOpenGLVertexArrayObject vao;
    QOpenGLBuffer vbo;
    bool initialized;

public:
    ShaderOnlyScene();
    ~ShaderOnlyScene();
    bool isInitialized() const;
    void initialize();
    void renderAt(float time);
    bool setShader(const QString& filename);
    void setViewportResolution(int w, int h);
};

#endif // SHADERONLYSCENE_H
