#ifndef __BLINKTASK__
#define __BLINKTASK__

#include <Arduino.h>

#include "Door.h"
#include "Led.h"
#include "Task.h"

class WasteSensor : public Task {
   private:
    int input;
    int output;
    int pinLed1;
    int pinLed2;
    Light* led1;
    Light* led2;
    Door* door;

    enum { FULL, NOTFULL } state;

    bool isFull();

   public:
    WasteSensor(int pin, int output, int pinLed1, int pinLed2, Door* door);
    void init(int period);
    void tick();
};

#endif