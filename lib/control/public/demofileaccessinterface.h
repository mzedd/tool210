#ifndef DEMOFILEACCESSINTERFACE_H
#define DEMOFILEACCESSINTERFACE_H

#include <vector>
#include <QString>
#include "Demo.h"

class DemoFileAccessInterface {
public:
    virtual ~DemoFileAccessInterface() {};
    virtual Tool210::Entities::Demo *getDemo(QString filepath) = 0;
    virtual void storeDemo(QString filepath, Tool210::Entities::Demo *demo) = 0;
};

#endif // DEMOFILEACCESSINTERFACE_H
