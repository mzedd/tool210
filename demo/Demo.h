#ifndef DEMO_H
#define DEMO_H


class Demo
{
private:
    Demo();

public:
    Demo(const Demo&) = delete;
    Demo(Demo&&) = delete;
    Demo& operator=(const Demo&) = delete;
    Demo& operator=(Demo&&) = delete;

    static Demo& instance();
};

#endif // DEMO_H
