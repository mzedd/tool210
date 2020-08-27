#include "Timeline.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

Timeline::Timeline(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout();
    QHBoxLayout *secondaryLayout = new QHBoxLayout();
    runPauseButton = new QPushButton("Play/Pause");
    timeLabel = new QLabel("Moin");
    hallo = new QLabel("tach");

    mainLayout->addLayout(secondaryLayout);
    mainLayout->addWidget(hallo);

    secondaryLayout->addWidget(runPauseButton);
    secondaryLayout->addStretch();
    secondaryLayout->addWidget(timeLabel);

    setLayout(mainLayout);
}
