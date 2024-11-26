#include "UserSensor.h"

#include <Arduino.h>

#include "Lcd.h"
#include "Light.h"

UserSensor::UserSensor(int output, int pinLed1, int pinLed2, float tSleep) {
    this->output = output;
    this->pinLed1 = pinLed1;
    this->pinLed2 = pinLed2;
    this->tSleep = tSleep;
}

void UserSensor::init(int period) {
    Task::init(period);
    led1 = new Led(pinLed1);
    led2 = new Led(pinLed2);
    state = ACTIVE;
    led1->switchOn();
    led2->switchOff();
    pinMode(output, INPUT);
}

void UserSensor::tick() {
    if (state == ACTIVE) {
        if (isFar()) {
            if (timeZero == 0) {
                this->timeZero = millis();
            }
            // Controlla se è passato abbastanza tempo
            if (millis() - this->timeZero > tSleep) {
                state = AFK;
                timeZero = 0;
                led1->switchOn();
                led2->switchOff();
            }
        } else {
            // Se l'utente torna, resetta il timer
            timeZero = 0;
        }
    } else if (state == AFK) {
        if (!isFar()) {
            state = ACTIVE;
        }
    }
}

bool UserSensor::isFar() { return digitalRead(output) == LOW; }