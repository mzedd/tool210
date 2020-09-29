#ifndef RENDERER_H
#define RENDERER_H

#include <string>

class Clip;

class Renderer
{
    virtual void setClipToRender(Clip *clip) = 0;
    virtual void renderAt(float time) = 0;
    virtual void setViewport(int width, int height) = 0;
    virtual void addShader(int id, std::string filepath);
    virtual void removeShader(int id) = 0;
};

#endif // RENDERER_H
