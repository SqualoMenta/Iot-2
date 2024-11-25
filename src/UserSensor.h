#ifndef __BLINKTASK__
#define __BLINKTASK__

#include <Arduino.h>
#include "Led.h"
#include "Task.h"

class UserSensor : public Task
{
private:
    int output;
    int pinLed1;
    int pinLed2;
    Light *led1;
    Light *led2;
    float tSleep;
    unsigned long timeZero;

    enum
    {
        ACTIVE,
        AFK
    } state;

public:
    UserSensor(int output, int pinLed1, int pinLed2, float tSleep);
    void init(int period);
    void tick();
    bool isFar();
};

#endif