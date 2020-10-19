#ifndef EDITORCONTEXT_H
#define EDITORCONTEXT_H

namespace Tool210 {
namespace Entities {
class Clip;
}
}

class EditorContext
{
public:
    EditorContext();

    Tool210::Entities::Clip *getSelectedClip();
    void setSelectedClip(Tool210::Entities::Clip *selectedClip);

private:
    Tool210::Entities::Clip *selectedClip;
};

#endif // EDITORCONTEXT_H
