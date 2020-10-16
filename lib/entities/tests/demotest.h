#ifndef DEMOTEST_H
#define DEMOTEST_H

#include <QObject>
#include <QtTest/QTest>

class DemoTest : public QObject
{
    Q_OBJECT

private slots:
    void addClip();
    void addClipAndScene();

};

#endif // DEMOTEST_H
