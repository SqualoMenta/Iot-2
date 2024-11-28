#ifndef __DOORTASK__
#define __DOORTASK__

#include <Arduino.h>

#include "Motor.h"
#include "Lcd.h"
#include "Task.h"

class Door : public Task
{
private:
    Motor* motor;
    enum
    {
        OPENING,
        OPEN,
        CLOSING,
        CLOSED,
        NOMESSAGE,
        OFF
    } state;
    unsigned long T1;
    unsigned long t0;
    unsigned long T2;

public:
    void init(int period);
    Door(Motor* motor, unsigned long T1 = 10000, unsigned long T2 = 3000);
    void tick();
    void Door::open();
    void Door::close();
    void Door::shutDown();
    void Door::externalOn();
};

#endif
