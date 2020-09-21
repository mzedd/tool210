#ifndef DEMOFILEACCESSINTERFACE_H
#define DEMOFILEACCESSINTERFACE_H

#include <vector>
#include "Demo.h"

class DemoFileAccessInterface {
public:
    virtual ~DemoFileAccessInterface() {};
    virtual Demo *getDemo() = 0;
    virtual void storeDemo(QString filepath, Demo *demo) = 0;
};

#endif // DEMOFILEACCESSINTERFACE_H
