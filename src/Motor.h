#ifndef __MOTOR__
#define __MOTOR__

#include <Arduino.h>
#include <Servo.h>

class Motor
{
private:
    Servo motor;

public:
    Motor(int pin);
    void open();
    void close();
};

#endif