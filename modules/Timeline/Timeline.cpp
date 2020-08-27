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
    timeLabel = new QLabel("Moin");
    ClipListView *clipListView = new ClipListView(this);
    clipListView->setModel(new ClipListModel(this));

    mainLayout->addLayout(secondaryLayout);
    mainLayout->addWidget(clipListView);

    secondaryLayout->addWidget(runPauseButton);
    secondaryLayout->addStretch();
    secondaryLayout->addWidget(timeLabel);

    setLayout(mainLayout);
}
