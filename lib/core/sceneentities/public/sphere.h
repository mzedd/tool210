#ifndef SPHERE_H
#define SPHERE_H

#include "atomicsigneddistanceobject.h"

namespace Tool210 {
namespace SceneEntities {

class Sphere : public AtomicSignedDistanceObject
{
public:
    Sphere();

    float getRadius();
    void setRadius(float radius);

    std::string getFunctionCall();
    std::string getCode();
private:
    float radius;
};

} // namespace SceneEntities
} // namespace Tool210

#endif // SPHERE_H
