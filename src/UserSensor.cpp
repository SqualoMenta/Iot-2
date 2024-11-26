#include "UserSensor.h"

#include <Arduino.h>
#include <avr/sleep.h>

#include "Lcd.h"
#include "Light.h"

UserSensor* UserSensor::instance = nullptr;

UserSensor::UserSensor(int output, int pinLed1, int pinLed2, float tSleep) {
    this->output = output;
    this->pinLed1 = pinLed1;
    this->pinLed2 = pinLed2;
    this->tSleep = tSleep;
    instance = this;
}

void UserSensor::init(int period) {
    Task::init(period);
    led1 = new Led(pinLed1);
    led2 = new Led(pinLed2);
    state = ACTIVE;
    led1->switchOn();
    led2->switchOff();
    pinMode(output, INPUT);
    attachInterrupt(digitalPinToInterrupt(output), UserSensor::onInterrupt,
                    HIGH);
}

void UserSensor::tick() {
    switch (state) {
        case ACTIVE:
            if (isFar()) {
                this->timeZero = millis();
                state = FAR;
            }
            break;

        case AFK:
            set_sleep_mode(SLEEP_MODE_PWR_DOWN);
            sleep_enable();
            sleep_mode();
            /* The program will continue from here. */
            /* First thing to do is disable sleep. */
            sleep_disable();
            break;

        case FAR:
            if (millis() - this->timeZero > tSleep) {
                state = AFK;
                led1->switchOn();
                led2->switchOff();
            }
            break;
    }
}

bool UserSensor::isFar() { return digitalRead(output) == LOW; }

void UserSensor::onInterrupt() {
    if (digitalRead(instance -> output) == HIGH) {
        instance -> state = ACTIVE;
    }
}