#include "Demo.h"

Demo::Demo()
{

}

Demo &Demo::instance()
{
    static Demo _instance;
    return _instance;
}
