#include "Demo.h"
#include "Clip.h"
#include "Scene.h"

Demo::Demo()
{

}

Demo::~Demo()
{
    for(auto scene : sceneList_) {
        if(scene)
            delete scene;
    }
}

std::string Demo::name() const
{
    return name_;
}

void Demo::setName(std::string name)
{
    name_ = name;
}

std::vector<Clip *> &Demo::clipList()
{
    return clipList_;
}

std::vector<Scene *> &Demo::sceneList()
{
    return sceneList_;
}

void Demo::addClip()
{
    clipList().push_back(new Clip());

    addScene();
    clipList().back()->setScene(sceneList_.back());
}

int Demo::sceneCount() const
{
    return sceneList_.size();
}

Scene *Demo::sceneAt(int index)
{
    for(Scene *scene : sceneList_) {
        if(scene->id() == index)
            return scene;
    }
    return nullptr;
}

void Demo::addScene()
{
    sceneList_.push_back(new Scene);
}

int Demo::clipIdAt(float time)
{
    float clipEndTime = 0.0f;

    for(unsigned int id = 0; id < clipList_.size(); id++) {
        clipEndTime += clipList_.at(id)->duration();
        if(time < clipEndTime)
            return static_cast<int>(id);
    }

    return -1;
}
