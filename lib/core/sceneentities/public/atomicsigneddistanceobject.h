#ifndef ATOMICSIGNEDDISTANCEOBJECT_H
#define ATOMICSIGNEDDISTANCEOBJECT_H

#include <string>

namespace Tool210 {
namespace SceneEntities {

class AtomicSignedDistanceObject {
public:
    virtual std::string getCode() = 0;
};

} // namespace Tool210
} // namespace SceneEntities

#endif // ATOMICSIGNEDDISTANCEOBJECT_H
