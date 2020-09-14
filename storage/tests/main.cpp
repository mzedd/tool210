#include "demofileaccessinterface.h"
#include "demojsonfileaccess.h"

#include <vector>
#include "models/Clip.h"
#include "models/Scene.h"

#include <QTextStream>

int main()
{
    DemoFileAccessInterface *demoFileAccess = new DemoJsonFileAccess("resources/demo.json");


    assert(!demoFileAccess->getDemoName().compare("Test Demo"));

    std::vector<Clip *> clipList = demoFileAccess->getClipList();
    for(Clip *clip : clipList) {
        QTextStream(stdout) << clip->name() << Qt::endl;
    }

    assert(!clipList.at(0)->name().compare("first clip"));
    assert(clipList.at(0)->name().compare("wrong clip name"));

    std::vector<Scene *> sceneList = demoFileAccess->getSceneList();
    for(Scene *scene : sceneList) {
        QTextStream(stdout) << scene->name() << Qt::endl;
    }

    return 0;
}
