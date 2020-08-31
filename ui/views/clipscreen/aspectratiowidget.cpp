#include "aspectratiowidget.h"

AspectRatioWidget::AspectRatioWidget(QWidget *widget, float aspectRatio, QWidget *parent) :
    QWidget(parent),
    layout(new QBoxLayout(QBoxLayout::LeftToRight, this)),
    aspectRatio(aspectRatio)
{
    layout->addStretch();
    layout->addWidget(widget);
    layout->addStretch();
}

// inpired by https://stackoverflow.com/questions/30005540/keeping-the-aspect-ratio-of-a-sub-classed-qwidget-during-resize
// credits to user Anthony
void AspectRatioWidget::resizeEvent(QResizeEvent *event)
{
    float outerWidgetAspectRatio = static_cast<float>(event->size().width()) / static_cast<float>(event->size().height());
    int widgetStretch, spacerStretch;

    if(outerWidgetAspectRatio < aspectRatio)
    {
        layout->setDirection(QBoxLayout::TopToBottom);
        widgetStretch = (1.0f / aspectRatio) * width();
        spacerStretch = (height() - widgetStretch) * 0.5;
    } else {
        layout->setDirection(QBoxLayout::LeftToRight);
        widgetStretch = aspectRatio * height();
        spacerStretch = (width() - widgetStretch) * 0.5;
    }

    layout->setStretch(0, spacerStretch);
    layout->setStretch(1, widgetStretch);
    layout->setStretch(2, spacerStretch);

    QWidget::resizeEvent(event);
}

