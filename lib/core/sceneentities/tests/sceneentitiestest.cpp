#include "sceneentitiestest.h"
#include "sphere.h"

void SceneEntitiesTest::sphereFunctionCall()
{
    Tool210::SceneEntities::Sphere sphere;

    sphere.setRadius(5.0f);
    QCOMPARE(sphere.getFunctionCall(), "sdSphere(p, 5.000);");

    sphere.setRadius(3.141f);
    QCOMPARE(sphere.getFunctionCall(), "sdSphere(p, 3.141);");
}

QTEST_MAIN(SceneEntitiesTest)
#include "sceneentitiestest.moc"
