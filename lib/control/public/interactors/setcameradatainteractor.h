#ifndef SETCAMERADATAINTERACTOR_H
#define SETCAMERADATAINTERACTOR_H

#include "interactors/camerainspectorinputboundary.h"

class SetCameraDataInteractor : public CameraInspectorInputBoundary
{
public:
    SetCameraDataInteractor();

    void setData(CameraData cameraData);
};

#endif // SETCAMERADATAINTERACTOR_H
