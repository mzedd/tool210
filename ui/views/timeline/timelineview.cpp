#include "timelineview.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include "cliplistview.h"
#include "cliplistmodel.h"
#include "rendercontext.h"

TimelineView::TimelineView(ClipListModel *model, QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout();
    QHBoxLayout *secondaryLayout = new QHBoxLayout();

    clipListView = new ClipListView(this);
    runPauseButton = new QPushButton("Play/Pause");
    addClipButton = new QPushButton("+");
    zoomLabel = new QLabel("Zoom: 100 %");
    timeLabel = new QLabel("Time: 10 s");

    clipListView->setModel(model);

    mainLayout->addLayout(secondaryLayout);
    mainLayout->addWidget(clipListView);

    secondaryLayout->addWidget(runPauseButton);
    secondaryLayout->addWidget(addClipButton);
    secondaryLayout->addWidget(timeLabel);
    secondaryLayout->addStretch();
    secondaryLayout->addWidget(zoomLabel);

    setLayout(mainLayout);

    connect(clipListView, SIGNAL(zoomChanged(float)), this, SLOT(setZoomLabel(float)));
    connect(runPauseButton, &QPushButton::clicked, this, &TimelineView::playPauseClicked);
    connect(addClipButton, &QPushButton::clicked, this, &TimelineView::addClipButtonClicked);
}

void TimelineView::setRenderContext(RenderContext *renderContext)
{
    this->renderContext = renderContext;
    clipListView->setRenderContext(renderContext);

    connect(renderContext, &RenderContext::timeChanged, this, &TimelineView::updateTimeLabel);
    connect(renderContext, &RenderContext::timeChanged, clipListView, &ClipListView::timeChanged);
}

void TimelineView::updateTimeLabel()
{
    timeLabel->setText(QString("Time: %1 s").arg(renderContext->time()));
}

void TimelineView::addClipButtonClicked()
{
    clipListView->model()->insertRow(0);
}

void TimelineView::setZoomLabel(float zoom)
{
    zoomLabel->setText(QString("Zoom: %1 %").arg(zoom*100.0f));
}

void TimelineView::playPauseClicked()
{
    renderContext->setRun(!renderContext->run());
}
