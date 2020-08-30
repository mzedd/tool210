#include "ShaderOnlyScene.h"

ShaderOnlyScene::ShaderOnlyScene()
{
    name = QString("default shader only scene");
}

ShaderOnlyScene::~ShaderOnlyScene()
{
    shaderProgram.release();
    vao.destroy();
    vbo.destroy();
}

void ShaderOnlyScene::initialize()
{
    shaderProgram.create();
    setShader("shader/default.frag");

    float vertices[] = {
        -1.0f, -1.0f, 0.0f,
         1.0f, -1.0f, 0.0f,
         1.0f,  1.0f, 0.0f,
        -1.0f, -1.0f, 0.0f,
         1.0f,  1.0f, 0.0f,
        -1.0f,  1.0f, 0.0f
    };

    vao.create();
    vao.bind();

    vbo.create();
    vbo.bind();
    vbo.allocate(vertices, sizeof (vertices));

    shaderProgram.enableAttributeArray(0);
    shaderProgram.setAttributeArray(0, GL_FLOAT, 0, 3);
}

void ShaderOnlyScene::renderAt(float time)
{
    vao.bind();

    shaderProgram.setUniformValue("iTime", time);
    shaderProgram.bind();
}

bool ShaderOnlyScene::setShader(const QString& filename)
{   
    // add and compile vertex shader
    QOpenGLShader vertShader(QOpenGLShader::Vertex);
    vertShader.compileSourceFile("shader/quad.vert");

    if(!vertShader.isCompiled()) {
        qDebug() << vertShader.log();
        return false;
    }

    // add and compile fragment shader
    QOpenGLShader fragShader(QOpenGLShader::Fragment);
    fragShader.compileSourceFile(filename);

    if(!fragShader.isCompiled()) {
        qDebug() << fragShader.log();
        return false;
    }

    // add and link shaders to program
    shaderProgram.addShader(&vertShader);
    shaderProgram.addShader(&fragShader);
    shaderProgram.link();

    if(!shaderProgram.isLinked()) {
        qDebug() << shaderProgram.log();
        return false;
    }

    return true;
}

void ShaderOnlyScene::setViewportResolution(int w, int h)
{
    shaderProgram.bind();
    shaderProgram.setUniformValue("iResolution", w, h);
}