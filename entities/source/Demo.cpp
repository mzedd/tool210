#include "Demo.h"
#include "ShaderOnlyScene.h"

Demo::Demo(std::vector<Clip *> *clipList, std::vector<Scene *> *sceneList) :
    clipList_(*clipList),
    sceneList_(*sceneList)
{

}

Demo::~Demo()
{
    for(auto scene : sceneList_) {
        if(scene)
            delete scene;
    }
}

QString Demo::name() const
{
    return name_;
}

void Demo::setName(QString name)
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
    clipList().back()->setDuration(20.0f);
    clipList().back()->setId(clipList().size() - 1);

    addScene();
    clipList().back()->setScene(sceneList_.back());
    emit clipAdded(clipList().back()->id());
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
    emit sceneAdded();
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
        clipEndTime += clipList_.at(id)->duration();
        if(time < clipEndTime)
            return static_cast<int>(id);
    }

    return -1;
}
