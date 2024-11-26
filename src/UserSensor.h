#ifndef __BLINKTASK__
#define __BLINKTASK__

#include <Arduino.h>

#include "Led.h"
#include "Task.h"

class UserSensor : public Task {
   private:
    int output;
    int pinLed1;
    int pinLed2;
    Light *led1;
    Light *led2;
    float tSleep;
    unsigned long timeZero;
    static UserSensor *instance;

    enum { ACTIVE, FAR, AFK } state;
    static void onInterrupt();

   public:
    UserSensor(int output, int pinLed1, int pinLed2, float tSleep = 10000);
    void init(int period);
    void tick();
    bool isFar();
};

#endif