#ifndef SETCAMERADATAINTERACTOR_H
#define SETCAMERADATAINTERACTOR_H

#include "interactors/camerainspectorinputboundary.h"
#include "interactors/camerainspectoroutputboundary.h"
#include "controllers/editorcontext.h"

class SetCameraDataInteractor : public CameraInspectorInputBoundary
{
public:
    SetCameraDataInteractor(CameraInspectorOutputBoundary *outputBoundary, EditorContext *editorContext);

    void setData(CameraData cameraData);

private:
    void writeDataToSelectedCamera(CameraData cameraData);
    CameraData readDataFromSelectedCamera();

    CameraInspectorOutputBoundary *outputBoundary;
    EditorContext *editorContext;
};

#endif // SETCAMERADATAINTERACTOR_H
