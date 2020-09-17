#ifndef SHADERONLYSCENE_H
#define SHADERONLYSCENE_H

#include "Scene.h"
#include <string>
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

    std::string shaderFileName_;

public:
    ShaderOnlyScene();
    ~ShaderOnlyScene();
    bool isInitialized() const;
    void initialize();
    void renderAt(float time);
    bool setShader(const QString& filename);
    std::string shaderFileName() const;
    void setViewportResolution(int w, int h);
};

#endif // SHADERONLYSCENE_H
