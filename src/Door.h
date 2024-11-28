#ifndef __DOORTASK__
#define __DOORTASK__

#include "Motor.h"
#include "Task.h"
#include "Timer.h"

class Door : public Task {
   private:
    Motor* motor;
    enum { OPENING, OPEN, CLOSING, CLOSED, NOMESSAGE, OFF } state;
    Timer timer1;
    Timer timer2;

   public:
    void init(int period);
    Door(int pin, unsigned long T1 = 10000, unsigned long T2 = 3000);
    void tick();
    void Door::open();
    void Door::close();
    void Door::shutDown();
    void Door::externalOn();
};

#endif
