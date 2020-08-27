#include "Timeline.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include "ClipListView.h"
#include "demo/ClipListModel.h"

Timeline::Timeline(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout();
    QHBoxLayout *secondaryLayout = new QHBoxLayout();
    runPauseButton = new QPushButton("Play/Pause");
    zoomLabel = new QLabel("Zoom: 100 %");
    timeLabel = new QLabel("Time: 10 s");
    ClipListView *clipListView = new ClipListView(this);
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
}

void Timeline::setZoomLabel(float zoom)
{
    zoomLabel->setText(QString("Zoom: %1 %").arg(zoom*100.0f));
}

void Timeline::setTimeLabel(float time)
{
    timeLabel->setText(QString("Time: %1 s").arg(time));
}