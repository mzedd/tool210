#include "demotest.h"
#include "demo.h"

void DemoTest::addClip()
{
    Tool210::Entities::Demo demo;

    demo.addClip();
    demo.clipList().at(0)->setName("first clip");

    QCOMPARE(demo.clipList().at(0)->name(), "first clip");
}

void DemoTest::addClipAndScene()
{
    Tool210::Entities::Demo demo;

    demo.addClip();
    demo.addScene();

    QCOMPARE(demo.sceneAt(0)->id(), 0);
}

QTEST_MAIN(DemoTest)
#include "demotest.moc"
