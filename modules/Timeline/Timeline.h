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
    QLabel *zoomLabel;
    QLabel *timeLabel;

private slots:
    void setZoomLabel(float zoom);
    void setTimeLabel(float time);
};

#endif // TIMELINE_H
