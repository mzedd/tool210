#include "demofileaccessinterface.h"
#include "demofileaccess.h"

#include <QTextStream>

int main()
{
    DemoFileAccessInterface *demoFileAccess = new DemoFileAccess();

    QTextStream(stdout) << demoFileAccess->getDemoName() << Qt::endl;

    return 0;
}
