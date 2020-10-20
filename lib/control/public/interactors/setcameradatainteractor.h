#ifndef SETCAMERADATAINTERACTOR_H
#define SETCAMERADATAINTERACTOR_H

#include "interactors/camerainspectorinputboundary.h"
#include "interactors/camerainspectoroutputboundary.h"
#include "controllers/renderer.h"

class EditorContext;

class SetCameraDataInteractor : public CameraInspectorInputBoundary
{
public:
    SetCameraDataInteractor(CameraInspectorOutputBoundary *outputBoundary, EditorContext *editorContext, Renderer *renderer);

    void setData(CameraData cameraData);
    void selectedClipChanged();

private:
    void writeDataToSelectedCamera(CameraData cameraData);
    CameraData readDataFromSelectedCamera();

    CameraInspectorOutputBoundary *outputBoundary;
    EditorContext *editorContext;
    Renderer *renderer;
};

#endif // SETCAMERADATAINTERACTOR_H
