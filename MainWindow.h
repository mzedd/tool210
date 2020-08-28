#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QElapsedTimer>
#include "modules/ClipScreen/ClipScreen.h"
#include "modules/Timeline/Timeline.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    void createMenu();
    void createInitialWidgets();
    void setupConnections();

    QElapsedTimer timer;
    float time;
    float startTime;
    ClipScreen *clipScreen;
    Timeline *timeline;

signals:
    void playPauseDemo();
    void timeChanged(float time);

public slots:
    void frameFinished();
    void setTime(float time);
};
#endif // MAINWINDOW_H
