#include "clipscreenview.h"
#include <QVBoxLayout>
#include <QOpenGLWidget>

#include "rendercontext.h"

constexpr float ASPECT_RATIO = 16.0f/9.0f;

ClipScreenView::ClipScreenView(OpenGLScreen *screen, QWidget *parent) :
    QWidget(parent)
{
    openGLScreen = screen;
    aspectRatioWidget = new AspectRatioWidget(openGLScreen, ASPECT_RATIO, this);
    openGLScreen->setParent(aspectRatioWidget);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(aspectRatioWidget);
}

QSize ClipScreenView::sizeHint() const
{
    return QSize(600, 500);
}

void ClipScreenView::setRenderContext(RenderContext *renderContext)
{
    openGLScreen->setRenderContext(renderContext);
    connect(renderContext, SIGNAL(timeChanged()), openGLScreen, SLOT(update()));
    connect(renderContext, &RenderContext::runChanged, openGLScreen, QOverload<>::of(&QOpenGLWidget::update));
}
