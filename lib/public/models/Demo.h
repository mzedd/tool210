#ifndef DEMO_H
#define DEMO_H

#include <vector>
#include <QObject>
#include "Clip.h"
#include "Scene.h"

class Q_DECL_EXPORT Demo : public QObject
{
    Q_OBJECT

public:
    Demo();
    Demo(std::vector<Clip *> clipList, std::vector<Scene *> sceneList);
    ~Demo();
    Q_DISABLE_COPY_MOVE(Demo)

    QString name() const;
    void setName(QString name);

    std::vector<Clip *> &clipList();
    std::vector<Scene *> &sceneList();

    void addClip();
    void checkClipToBeRenderdChangedAt(float time);

    int sceneCount() const;
    Scene *sceneAt(int index);
    void addScene();
    void initializeShaders(int w, int h);

private:
    QString name_;
    std::vector<Clip *> clipList_;
    std::vector<Scene *> sceneList_;

    // TODO: musicTrack
    // TODO: postProcessingEffects

    int clipIdAt(float time);

Q_SIGNALS:
    void clipAdded(int id);
    void sceneAdded();
    void clipToRenderChanged(int id);

};

#endif // DEMO_H
