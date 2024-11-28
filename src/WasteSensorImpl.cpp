#include "WasteSensorImpl.h"

#include <Arduino.h>

WasteSensorImpl::WasteSensorImpl(int pin) { this->pin = pin; }

double WasteSensorImpl::newDistance() {
    long duration;
    pinMode(this->pin, OUTPUT);
    digitalWrite(this->pin, LOW);
    delayMicroseconds(2);
    digitalWrite(this->pin, HIGH);
    delayMicroseconds(5);
    digitalWrite(this->pin, LOW);
    pinMode(this->pin, INPUT);

    duration = pulseIn(this->pin, HIGH);

    this->oldDistance = (duration * 0.034) / 2;
    // 0.034 cm/µs is the sound speed

    return this->oldDistance;
}

double WasteSensorImpl::lastDistance() { return this->oldDistance; }