#include "openglrenderer.h"

OpenGLRenderer::OpenGLRenderer(QObject *parent) :
    QObject(parent),
    clipToRender(nullptr)
{

}

void OpenGLRenderer::initializeGL()
{
    float vertices[] = {
        -1.0f, -1.0f, 0.0f,
         1.0f, -1.0f, 0.0f,
         1.0f,  1.0f, 0.0f,
        -1.0f, -1.0f, 0.0f,
         1.0f,  1.0f, 0.0f,
        -1.0f,  1.0f, 0.0f
    };

    initializeOpenGLFunctions();

    vao.create();
    vao.bind();

    vbo.create();
    vbo.bind();
    vbo.allocate(vertices, sizeof (vertices));
}

void OpenGLRenderer::setRenderContext(RenderContext *renderContext)
{
    this->renderContext = renderContext;
}

void OpenGLRenderer::setClipToRender(Clip *clip)
{
    clipToRender = clip;
}

void OpenGLRenderer::renderAt(float time)
{
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(clipToRender)
    {
        int sceneId = clipToRender->scene()->id();
        QOpenGLShaderProgram *shaderProgram = shaderMap.value(sceneId);

        shaderProgram->bind();
        shaderProgram->setUniformValue("iTime", time);

        vao.bind();
        vbo.bind();

        glDrawArrays(GL_TRIANGLES, 0, 6);
    }
}

void OpenGLRenderer::setViewport(int width, int height)
{
    this->width = width;
    this->height = height;

    glViewport(0, 0, width, height);

    for(QOpenGLShaderProgram* program : shaderMap) {
        program->setUniformValue("iResolution", width, height);
    }
}

bool OpenGLRenderer::addShader(int id, std::string filepath)
{   
    QOpenGLShaderProgram *shaderProgram = new QOpenGLShaderProgram;

    // add and compile vertex shader
    QOpenGLShader vertShader(QOpenGLShader::Vertex);
    vertShader.compileSourceFile("resources/quad.vert");

    if(!vertShader.isCompiled()) {
        qWarning() << vertShader.log();
        return false;
    }

    // add and compile fragment shader
    QOpenGLShader fragShader(QOpenGLShader::Fragment);
    fragShader.compileSourceFile(QString::fromStdString(filepath));

    if(!fragShader.isCompiled()) {
        qWarning() << fragShader.log();
        return false;
    }

    // add and link shaders to program
    shaderProgram->addShader(&vertShader);
    shaderProgram->addShader(&fragShader);
    shaderProgram->link();

    if(!shaderProgram->isLinked()) {
        qWarning() << shaderProgram->log();
        return false;
    }

    shaderProgram->enableAttributeArray(0);
    shaderProgram->setAttributeArray(0, GL_FLOAT, 0, 3);
    shaderProgram->setUniformValue("iResolution", width, height);

    shaderMap.insert(id, shaderProgram);
    return true;
}

void OpenGLRenderer::removeShader(int id)
{
    delete shaderMap.take(id);
}
