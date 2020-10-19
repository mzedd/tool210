#ifndef CAMERAINSPECTORINPUTBOUNDARY_H
#define CAMERAINSPECTORINPUTBOUNDARY_H

#include "cameradata.h"

class CameraInspectorInputBoundary {
public:
    virtual void setData(CameraData cameraData) = 0;

};

#endif // CAMERAINSPECTORINPUTBOUNDARY_H
