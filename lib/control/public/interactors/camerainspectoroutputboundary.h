#ifndef CAMERAINSPECTOROUTPUTBOUNDARY_H
#define CAMERAINSPECTOROUTPUTBOUNDARY_H

#include "cameradata.h"

class CameraInspectorOutputBoundary {
public:
    virtual void present(CameraData cameraData) = 0;
};

#endif // CAMERAINSPECTOROUTPUTBOUNDARY_H
