#include "UserSensor.h"

#include <Arduino.h>
#include <avr/sleep.h>

#include "SystemCommand.h"

UserSensor* UserSensor::instance = nullptr;

UserSensor::UserSensor(int output, float tSleep) {
    this->output = output;
    this->timer.setupPeriod(tSleep);
    instance = this;
}

void UserSensor::init(int period) {
    Task::init(period);
    state = ACTIVE;
    pinMode(output, INPUT);
    attachInterrupt(digitalPinToInterrupt(output), UserSensor::onInterrupt,
                    HIGH);
}

void UserSensor::tick() {
    switch (state) {
        case ACTIVE:
            if (isFar()) {
              //Serial.println("Far");
                this->timer.resetTimer();
                state = FAR;
            }
            break;

        case AFK:
        //Serial.println("Sleep");
            set_sleep_mode(SLEEP_MODE_PWR_DOWN);
            sleep_enable();
            sleep_mode();
            /* The program will continue from here. */
            /* First thing to do is disable sleep. */
            sleep_disable();
            break;

        case FAR:
            if (isFar()) {
                if (this->timer.isPeriodPassed()) {
                    state = AFK;
                }
            } else {
                state = ACTIVE;
            }
            break;
    }
}

bool UserSensor::isFar() { return digitalRead(output) == LOW; }

void UserSensor::onInterrupt() {
    if (digitalRead(instance->output) == HIGH) {
        instance->state = ACTIVE;
    }
}