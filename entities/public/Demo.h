#ifndef DEMO_H
#define DEMO_H

#include <vector>
#include <string>

class Clip;
class Scene;

class Demo
{
public:
    Demo(std::vector<Clip *> *clipList, std::vector<Scene *> *sceneList);
    ~Demo();

    std::string name() const;
    void setName(std::string name);

    std::vector<Clip *> &clipList();
    std::vector<Scene *> &sceneList();

    void addClip();
    int clipIdAt(float time);

    int sceneCount() const;
    Scene *sceneAt(int index);
    void addScene();

private:
    std::string name_;
    std::vector<Clip *> &clipList_;
    std::vector<Scene *> &sceneList_;

    // TODO: musicTrack
    // TODO: postProcessingEffects
};

#endif // DEMO_H
