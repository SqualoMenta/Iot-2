#ifndef __BLINKTASK__
#define __BLINKTASK__

#include "Task.h"

#include "Led.h"

class TemperatureSensor : public Task
{

    int pin;
    int pinLed1;
    int pinLed2;
    int pinButton;
    float maxTemp;
    float maxTempTime;
    Light *led1;
    Light *led2;
    unsigned long timeZero;

    enum
    {
        OK,
        HOT,
        PROBLEM
    } state;

public:
    TemperatureSensor(int pin, int pinLed1, int pinLed2, int pinButton, float maxTemp, float maxTempTime);
    void init(int period);
    void tick();
};

#endif