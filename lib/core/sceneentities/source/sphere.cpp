#include "sphere.h"
#include <algorithm>
#include <sstream>
#include <iomanip>

namespace Tool210 {
namespace SceneEntities {

Sphere::Sphere() :
    radius(1.0f)
{

}

float Sphere::getRadius()
{
    return radius;
}

void Sphere::setRadius(float radius)
{
    this->radius = std::max(0.0f, radius);
}

std::string Sphere::getFunctionCall()
{
    std::stringstream sstream;
    sstream << "sdSphere(p, ";
    sstream << std::fixed << std::setprecision(3);
    sstream << radius;
    sstream << ");";

    return sstream.str();
}

std::string Tool210::SceneEntities::Sphere::getCode()
{
    return
            "float sdSpheren(in vec3 p, in float r) {"
            "   return length(p) - r;"
            "}";
}

} // namespace SceneEntities
} // namespace Tool210
