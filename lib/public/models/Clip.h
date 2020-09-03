#ifndef CLIP_H
#define CLIP_H

#include <QString>
#include <QObject>
#include "Scene.h"

class Clip : public QObject
{
    Q_OBJECT

public:
    Clip();
    void renderAt(float time);
    QString name() const;
    void setName(QString name);
    float getDuration();
    void setDuration(float duration);
    Scene *getScene();
    void setScene(Scene *scene);

private:
    QString name_;
    float duration;
    Scene *scene;
};

#endif // CLIP_H
