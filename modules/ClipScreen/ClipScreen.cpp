#include "ClipScreen.h"
#include "OpenGLScreen.h"

constexpr float ASPECT_RATIO = 16.0/9.0;

ClipScreen::ClipScreen(QWidget *parent) :
    QWidget(parent)
{
    layout = new QBoxLayout(QBoxLayout::LeftToRight, this);

    layout->addStretch();
    layout->addWidget(new OpenGLScreen(this));
    layout->addStretch();
}

ClipScreen::~ClipScreen()
{

}

void ClipScreen::resizeEvent(QResizeEvent *event)
{
    float outerWidgetAspectRatio = static_cast<float>(event->size().width()) / static_cast<float>(event->size().height());
    int widgetStretch, spacerStretch;

    if(outerWidgetAspectRatio < ASPECT_RATIO)
    {
        layout->setDirection(QBoxLayout::TopToBottom);
        widgetStretch = (1.0f / ASPECT_RATIO) * width();
        spacerStretch = (height() - widgetStretch) * 0.5;
    } else {
        layout->setDirection(QBoxLayout::LeftToRight);
        widgetStretch = ASPECT_RATIO * height();
        spacerStretch = (width() - widgetStretch) * 0.5;
    }

    layout->setStretch(0, spacerStretch);
    layout->setStretch(1, widgetStretch);
    layout->setStretch(2, spacerStretch);

    QWidget::resizeEvent(event);
}
