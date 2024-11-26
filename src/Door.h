#ifndef DOOR_H
#define DOOR_H

#include <Arduino.h>
#include <Servo.h>

#include "Task.h"

class Door : public Task {
   private:
    Servo motor;
    enum { OPENING, CLOSING, CLOSED, NOMESSAG, OFF } state;
    const long T1 = 10000;
    unsigned long t0;
    const long T2 = 3000;

   public:
    void init(int period);
    void open();
    void close();
    void externalOn();
    void shutDown();
    Door(int pin);
    void tick();
};

#endif
