#ifndef SCENE_H
#define SCENE_H

#include <string>

namespace Tool210 {
namespace Entities {

class Scene
{
public:
    Scene();

    int id() const;

    std::string name() const;
    void setName(std::string name);

    std::string shaderFileName() const;
    void setShaderFileName(std::string filename);

protected:
    int id_;
    std::string name_;
    std::string shaderFileName_;
};

} // namespace Entities
} // namespace Tool210

#endif // SCENE_H
