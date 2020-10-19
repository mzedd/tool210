#include "interactors/setcameradatainteractor.h"
#include "clip.h"
#include "camera.h"

SetCameraDataInteractor::SetCameraDataInteractor(CameraInspectorOutputBoundary *outputBoundary, EditorContext *editorContext) :
    outputBoundary(outputBoundary),
    editorContext(editorContext)
{

}

void SetCameraDataInteractor::setData(CameraData cameraData)
{
    writeDataToSelectedCamera(cameraData);

    CameraData newCameraData = readDataFromSelectedCamera();
    outputBoundary->present(newCameraData);
}

void SetCameraDataInteractor::writeDataToSelectedCamera(CameraData cameraData)
{
    Tool210::Entities::Camera &camera = editorContext->getSelectedClip()->getCamera();

    camera.position = cameraData.position;
    camera.setLookAtPoint(cameraData.lookAt);
    camera.setUpVector(cameraData.up);
    camera.zoom = cameraData.zoom;
}

CameraData SetCameraDataInteractor::readDataFromSelectedCamera()
{
    Tool210::Entities::Camera &camera = editorContext->getSelectedClip()->getCamera();
    CameraData cameraData;

    cameraData.position = camera.position;
    cameraData.lookAt = camera.lookAt;
    cameraData.up = camera.getUpVector();
    cameraData.zoom = camera.getZoom();

    return cameraData;
}
