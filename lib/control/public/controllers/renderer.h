#ifndef RENDERER_H
#define RENDERER_H

#include <string>

namespace Tool210 {
namespace Entities {
    class Clip;
}
}

class Renderer
{
public:
    virtual void setClipToRender(Tool210::Entities::Clip *clip) = 0;
    virtual void renderAt(float time) = 0;
    virtual void setViewport(int width, int height) = 0;
    virtual bool addShader(int id, std::string filepath) = 0;
    virtual void removeShader(int id) = 0;
};

#endif // RENDERER_H
