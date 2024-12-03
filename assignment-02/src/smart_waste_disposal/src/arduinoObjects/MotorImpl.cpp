#include "include/arduinoObjects/MotorImpl.h"

MotorImpl::MotorImpl(int pin) {
    this->motor.attach(pin);
    this->motor.write(0);
}

void MotorImpl::open() { motor.write(90); }

void MotorImpl::close() { motor.write(0); }