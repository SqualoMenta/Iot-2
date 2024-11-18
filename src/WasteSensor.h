#ifndef __BLINKTASK__
#define __BLINKTASK__

#include "Task.h"

class WasteSensor : public Task
{

    int input;
    int output;
    enum
    {
        FULL,
        NOTFULL
    } state;

public:
    WasteSensor(int pin, int output);
    void init(int period);
    void tick();
};

#endif