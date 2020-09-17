#include "demofileaccessinterface.h"
#include "demojsonfileaccess.h"

#include <vector>
#include "models/Demo.h"

#include <iostream>

int main()
{
    DemoFileAccessInterface *demoFileAccess = new DemoJsonFileAccess("resources/demo.json");

    Demo *demo = demoFileAccess->getDemo();

    assert(!demo->name().compare("Test Demo"));

    std::vector<Clip *> clipList = demo->clipList();
    for(Clip *clip : clipList) {
        std::cout << clip->name().toStdString() << std::endl;
    }

    assert(!clipList.at(0)->name().compare("first clip"));
    assert(clipList.at(0)->name().compare("wrong clip name"));

    std::vector<Scene *> sceneList = demo->sceneList();
    for(Scene *scene : sceneList) {
        std::cout << scene->name().toStdString() << std::endl;
    }

    assert(!clipList.at(0)->scene()->name().compare("FirstScene"));
    assert(clipList.at(0)->scene()->name().compare("Wrong Scene"));

    return 0;
}
