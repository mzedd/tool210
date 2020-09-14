#include "demofileaccessinterface.h"
#include "demojsonfileaccess.h"

#include <vector>
#include "models/Demo.h"

#include <QTextStream>

int main()
{
    DemoFileAccessInterface *demoFileAccess = new DemoJsonFileAccess("resources/demo.json");

    Demo *demo = demoFileAccess->getDemo();

    assert(!demo->name().compare("Test Demo"));

    std::vector<Clip *> clipList = demo->clipList();
    for(Clip *clip : clipList) {
        QTextStream(stdout) << clip->name() << Qt::endl;
    }

    assert(!clipList.at(0)->name().compare("first clip"));
    assert(clipList.at(0)->name().compare("wrong clip name"));

    std::vector<Scene *> sceneList = demo->sceneList();
    for(Scene *scene : sceneList) {
        QTextStream(stdout) << scene->name() << Qt::endl;
    }

    return 0;
}
