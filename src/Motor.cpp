#include "Motor.h"

Motor::Motor(int pin){
    this->motor.attach(pin);
}

void Motor::open(){
    motor.write(90);
}

void Motor::close(){
    motor.write(0);
}