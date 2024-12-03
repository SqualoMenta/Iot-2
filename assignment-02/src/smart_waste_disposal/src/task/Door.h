#ifndef __DOORTASK__
#define __DOORTASK__

#include "arduinoObjects/Motor.h"
#include "kernel/Timer.h"
#include "task/Task.h"

class Door : public Task {
   private:
    Motor* motor;
    enum { OPENING, OPEN, CLOSING, CLOSED, NOMESSAGE, OFF } state;
    Timer timer1;
    Timer timer2;

   public:
    Door(int pin, unsigned long T1 = 10000, unsigned long T2 = 3000);
    void tick();
    void Door::open();
    void Door::close();
    void Door::shutDown();
    void Door::externalOn();
};

#endif
