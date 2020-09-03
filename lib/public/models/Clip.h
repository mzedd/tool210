#ifndef CLIP_H
#define CLIP_H

#include <QString>
#include <QObject>
#include "Scene.h"

class Q_DECL_EXPORT Clip : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(float duration READ duration WRITE setDuration NOTIFY durationChanged)
    Q_PROPERTY(Scene* Scene READ scene WRITE setScene NOTIFY sceneChanged)

public:
    Clip(QObject *parent = nullptr);
    void renderAt(float time);

    QString name() const;
    void setName(QString name);

    float duration() const;
    void setDuration(float duration);

    Scene *scene() const;
    void setScene(Scene *scene);

private:
    QString name_;
    float duration_;
    Scene *scene_;

Q_SIGNALS:
    void nameChanged();
    void durationChanged();
    void sceneChanged();
};

#endif // CLIP_H
