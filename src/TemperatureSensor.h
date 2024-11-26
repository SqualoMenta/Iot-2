#ifndef __BLINKTASK__
#define __BLINKTASK__

#include "Door.h"
#include "Led.h"
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
    Door* door;

    enum { OK, HOT, PROBLEM } state;

    bool isHot();

   public:
    TemperatureSensor(int pin, int pinLed1, int pinLed2, int pinButton,
                      float maxTemp, float maxTempTime, Door* door);
    void init(int period);
    void tick();
    float temperature();
    void restore();
};

#endif