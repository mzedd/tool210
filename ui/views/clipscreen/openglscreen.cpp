#include "openglscreen.h"
#include <QtDebug>
#include "rendercontext.h"

OpenGLScreen::OpenGLScreen(QWidget* parent) :
    QOpenGLWidget(parent),
    clipToRender(nullptr),
    renderContext(nullptr)
{

}

OpenGLScreen::~OpenGLScreen()
{
    makeCurrent();
}

void OpenGLScreen::setRenderContext(RenderContext *renderContext)
{
    this->renderContext = renderContext;
}

void OpenGLScreen::initializeGL()
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

void OpenGLScreen::resizeGL(int w, int h)
{
    setViewport(w, h);
}

void OpenGLScreen::paintGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(clipToRender == nullptr)
        return;

    if(clipToRender->scene() == nullptr)
        return;

    int sceneId = clipToRender->scene()->id();
    QOpenGLShaderProgram *shaderProgram = shaderMap.value(sceneId);

    shaderProgram->bind();
    shaderProgram->setUniformValue("iTime", renderContext->time());

    vao.bind();
    vbo.bind();

    glDrawArrays(GL_TRIANGLES, 0, 6);

    if(renderContext->run()) {
        emit frameFinishedAt(renderContext->deltaTime());
        update();
    }
}

void OpenGLScreen::setClipToRender(Clip *clip)
{
    clipToRender = clip;
}

void OpenGLScreen::renderAt(float time)
{
    update();
}

void OpenGLScreen::setViewport(int width, int height)
{
    this->width = width;
    this->height = height;

    glViewport(0, 0, width, height);

    for(QOpenGLShaderProgram* program : shaderMap) {
        program->bind();
        program->setUniformValue("iResolution", width, height);
    }
}

bool OpenGLScreen::addShader(int id, std::string filepath)
{
    makeCurrent();
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
    shaderProgram->bind();
    shaderProgram->setUniformValue("iResolution", width, height);

    shaderMap.insert(id, shaderProgram);
    renderContext->setTime(renderContext->time()); // hacky
    update();

    return true;
}

void OpenGLScreen::removeShader(int id)
{
    delete shaderMap.take(id);
}
