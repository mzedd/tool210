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

std::vector<Scene *> *Demo::sceneList()
{
    return &sceneList_;
}

void Demo::addClip()
{
    clipList()->push_back(Clip());
    clipList()->back().setDuration(20.0f);

    addScene();
    clipList()->at(clipList()->size()-1).setScene(sceneList_.at(sceneList_.size()-1));

    emit clipCreated(clipList()->size() - 1);
}

void Demo::checkClipToBeRenderdChangedAt(float time)
{
    emit clipToRenderChanged(clipIdAt(time));
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

int Demo::clipIdAt(float time)
{
    float clipEndTime = 0.0f;

    for(unsigned int id = 0; id < clipList_.size(); id++) {
        clipEndTime += clipList_.at(id).getDuration();
        if(time <= clipEndTime)
            return static_cast<int>(id);
    }

    return -1;
}
