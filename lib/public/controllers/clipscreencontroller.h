#ifndef CLIPSCREENCONTROLLER_H
#define CLIPSCREENCONTROLLER_H

#include <QObject>

class ClipScreenController : public QObject
{
    Q_OBJECT
public:
    explicit ClipScreenController(QObject *parent = nullptr);

signals:

};

#endif // CLIPSCREENCONTROLLER_H
