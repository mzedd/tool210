#include "clipscreenview.h"
#include <QVBoxLayout>

constexpr float ASPECT_RATIO = 16.0/9.0;

ClipScreenView::ClipScreenView(OpenGLModel *model, QWidget *parent) :
    QWidget(parent)
{
    openGLScreen = new OpenGLScreen(model);
    aspectRatioWidget = new AspectRatioWidget(openGLScreen, ASPECT_RATIO, this);
    openGLScreen->setParent(aspectRatioWidget);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(aspectRatioWidget);

    connect(model, SIGNAL(clipToRenderChanged()), openGLScreen, SLOT(update()));
    connect(model, SIGNAL(timeChanged()), openGLScreen, SLOT(update()));
    connect(model, SIGNAL(runChanged()), openGLScreen, SLOT(update()));
}

void ClipScreenView::setController(ClipScreenController *clipScreenController)
{
    this->clipScreenController = clipScreenController;
    connect(openGLScreen, SIGNAL(frameFinishedAt(float)), clipScreenController, SIGNAL(frameFinishedAt(float)));
}
