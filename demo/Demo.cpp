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
