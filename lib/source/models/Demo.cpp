#include "Demo.h"
#include "ShaderOnlyScene.h"

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

std::vector<Clip> *Demo::clipList()
{
    return &clipList_;
}

void Demo::addClip()
{
    clipList()->push_back(Clip());
    clipList()->back().setDuration(10.0f);

    emit clipCreated(clipList()->size() - 1);
}

int Demo::sceneCount() const
{
    return sceneList_.size();
}

Scene *Demo::sceneAt(int index)
{
    return sceneList_.at(index);
}

void Demo::addScene()
{
    sceneList_.push_back(new ShaderOnlyScene);
}

void Demo::initializeShaders(int w, int h)
{
    for(Scene* scene : sceneList_) {
        scene->initialize();
        scene->setViewportResolution(w, h);
    }
}
