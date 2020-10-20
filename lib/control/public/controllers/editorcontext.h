#ifndef EDITORCONTEXT_H
#define EDITORCONTEXT_H

#include "interactors/setcameradatainteractor.h"

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

    void setCameraDataInteractor(SetCameraDataInteractor *interactor);

    bool isClipSelected();

private:
    Tool210::Entities::Clip *selectedClip;
    SetCameraDataInteractor *cameraDataInteractor;
};

#endif // EDITORCONTEXT_H
