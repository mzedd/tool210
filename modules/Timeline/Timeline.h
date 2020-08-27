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

private slots:
    void setZoomLabel(float zoom);
};

#endif // TIMELINE_H
