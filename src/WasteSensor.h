#ifndef __WASTETASK__
#define __WASATETASK__

#include <Arduino.h>

#include "Door.h"
#include "Led.h"
#include "Light.h"
#include "SystemCommand.h" 
#include "Lcd.h"
#include "Task.h"

class WasteSensor : public Task {
   private:
    int input;
    int output;
    int pinLed1;
    int pinLed2;
    Light* led1;
    Light* led2;

    enum { FULL, NOTFULL } state;

    bool isFull();

   public:
    WasteSensor(int pin, int output, int pinLed1, int pinLed2);
    void init(int period);
    void tick();
    void clean();
};

#endif