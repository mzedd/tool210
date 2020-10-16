#include <iostream>
#include <vector>
#include <cassert>

#include "Demo.h"
#include "Clip.h"
#include "Scene.h"

int main()
{
    Tool210::Entities::Demo demo;

    demo.addClip();
    demo.clipList().at(0)->setName("first clip");

    assert(!demo.clipList().at(0)->name().compare("first clip"));
    assert(demo.sceneAt(0)->id() == 0);

    demo.addClip();
    assert(demo.sceneAt(1)->id() == 1);

    std::cout << "All tests were successfull" << std::endl;

    return 0;
}
