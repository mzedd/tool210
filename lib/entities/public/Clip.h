#ifndef CLIP_H
#define CLIP_H

#include <string>
#include "Scene.h"
#include "camera.h"

namespace Tool210 {
namespace Entities {

class Clip
{

public:
    Clip();

    std::string name() const;
    void setName(std::string name);

    float duration() const;
    void setDuration(float duration);

    Scene *scene() const;
    void setScene(Scene *scene);

    Camera &getCamera();

private:
    std::string name_;
    float duration_;
    Scene *scene_;
    Camera camera;

};

} // namespace Entities
} // namespace Tool210

#endif // CLIP_H
