#ifndef DEMOFILEACCESSINTERFACE_H
#define DEMOFILEACCESSINTERFACE_H

#include <vector>
#include "models/Demo.h"

class DemoFileAccessInterface {
public:
    virtual Demo *getDemo() = 0;
};

#endif // DEMOFILEACCESSINTERFACE_H
