#ifndef TIMELINE_H
#define TIMELINE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class Timeline : public QWidget
{
    Q_OBJECT
public:
    explicit Timeline(QWidget *parent = nullptr);

private:
    QPushButton *runPauseButton;
    QLabel *timeLabel;
    QLabel *hallo;

signals:

};

#endif // TIMELINE_H
