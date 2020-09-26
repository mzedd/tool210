#include <iostream>
#include <vector>
#include <cassert>

#include "Demo.h"
#include "Clip.h"
#include "Scene.h"

int main()
{
    auto clipList = new std::vector<Clip *>();
    auto sceneList = new std::vector<Scene *>();

    Demo demo(clipList, sceneList);

    demo.addClip();
    demo.clipList().at(0)->setName("first clip");

    assert(!demo.clipList().at(0)->name().compare("first clip"));

    std::cout << "All tests were successfull" << std::endl;

    return 0;
}
