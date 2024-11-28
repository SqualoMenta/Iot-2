#include "MotorImpl.h"

MotorImpl::MotorImpl(int pin) { this->motor.attach(pin); }

void MotorImpl::open() { motor.write(90); }

void MotorImpl::close() { motor.write(0); }