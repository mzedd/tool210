#include "Timeline.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include "ClipListView.h"
#include "ClipListModel.h"

Timeline::Timeline(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout();
    QHBoxLayout *secondaryLayout = new QHBoxLayout();
    clipListView = new ClipListView(this);
    runPauseButton = new QPushButton("Play/Pause");
    zoomLabel = new QLabel("Zoom: 100 %");
    timeLabel = new QLabel("Time: 10 s");
    clipListView->setModel(new ClipListModel(this));

    mainLayout->addLayout(secondaryLayout);
    mainLayout->addWidget(clipListView);

    secondaryLayout->addWidget(runPauseButton);
    secondaryLayout->addWidget(timeLabel);
    secondaryLayout->addStretch();
    secondaryLayout->addWidget(zoomLabel);

    setLayout(mainLayout);

    connect(clipListView, SIGNAL(zoomChanged(float)), this, SLOT(setZoomLabel(float)));
    connect(clipListView, SIGNAL(timeChanged(float)), this, SLOT(setTimeLabel(float)));
    connect(clipListView, SIGNAL(timeChanged(float)), this, SIGNAL(timeChanged(float)));
    connect(clipListView, SIGNAL(clipToRenderChanged(int)), this, SIGNAL(clipToRenderChanged(int)));
}

void Timeline::setZoomLabel(float zoom)
{
    zoomLabel->setText(QString("Zoom: %1 %").arg(zoom*100.0f));
}

void Timeline::setTimeLabel(float time)
{
    timeLabel->setText(QString("Time: %1 s").arg(time));
}

void Timeline::setTime(float time)
{
    setTimeLabel(time);
    clipListView->setTime(time);
}
