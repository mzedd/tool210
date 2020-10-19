#include "editorcontext.h"

EditorContext::EditorContext() :
    selectedClip(nullptr)
{

}

Tool210::Entities::Clip *EditorContext::getSelectedClip()
{
    return selectedClip;
}

void EditorContext::setSelectedClip(Tool210::Entities::Clip *selectedClip)
{
    this->selectedClip = selectedClip;
}
