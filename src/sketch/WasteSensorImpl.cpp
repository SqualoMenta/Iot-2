#include "WasteSensorImpl.h"

#include <Arduino.h>

WasteSensorImpl::WasteSensorImpl(int trigger, int echo) {
    this->trigger = trigger;
    this->echo = echo;
    pinMode(this->trigger, OUTPUT);
    pinMode(this->echo, INPUT);
}

double WasteSensorImpl::newDistance() {
    long duration;
    digitalWrite(this->trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(this->trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(this->trigger, LOW);

    duration = pulseIn(this->echo, HIGH);

    this->oldDistance = (duration * 0.034) / 2;
    // 0.034 cm/µs is the sound speed

    return this->oldDistance;
}

double WasteSensorImpl::lastDistance() { return this->oldDistance; }