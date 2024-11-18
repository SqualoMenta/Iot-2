#ifndef __BLINKTASK__
#define __BLINKTASK__

#include "Task.h"

#include "Led.h"

class WasteSensor : public Task
{

    int input;
    int output;
    int pinLed1;
    int pinLed2;
    Light *led1;
    Light *led2;

    enum
    {
        FULL,
        NOTFULL
    } state;

public:
    WasteSensor(int pin, int output, int pinLed1, int pinLed2);
    void init(int period);
    void tick();
};

#endif