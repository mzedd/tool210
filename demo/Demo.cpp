#include "Demo.h"

Demo::Demo()
{

}

Demo::~Demo()
{
    for(auto scene : sceneList)
    {
        delete scene;
    }
}

Demo &Demo::instance()
{
    static Demo _instance;
    return _instance;
}

int Demo::clipCount() const
{
    return clipList.size();
}

Clip &Demo::clipAt(int index)
{
    return clipList.at(index);
}

void Demo::addClip()
{
    clipList.push_back(Clip());
}

bool Demo::swapClips(int first, int second)
{
    Clip tmp = clipList.at(first);
    clipList.at(first) = clipList.at(second);
    clipList.at(second) = tmp;

    return true;
}
