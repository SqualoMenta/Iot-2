#ifndef __TEMPERATURETASK__
#define __TEMPERATURETASK__

#include "Led.h"
#include "SystemCommand.h"
#include "Task.h"

class TemperatureSensor : public Task {
   private:
    int pin;
    int pinLed1;
    int pinLed2;
    int pinButton;
    float maxTemp;
    float maxTempTime;
    Light* led1;
    Light* led2;
    unsigned long timeZero;

    enum { OK, HOT, PROBLEM } state;

    bool isHot();

   public:
    TemperatureSensor(int pin, int pinLed1, int pinLed2, int pinButton,
                      float maxTemp, float maxTempTime);
    void init(int period);
    void tick();
    float temperature();
    void restore();
};

#endif