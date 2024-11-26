#include "Door.h"

#include "Lcd.h"

Door::Door(int pin) {
    this->motor.attach(pin);
    this->state = CLOSING;
}

void Door::open() {
    if (state != OFF) {
        state = OPENING;
        this->t0 = millis();
    }
}

void Door::close() {
    if (state == OPENING) {
        state = CLOSING;
    }
}

void Door::shutDown() {
    motor.write(0);
    state = OFF;
}

void Door::tick() {
    switch (state) {
        case OPENING:
            if (millis() - this->t0 > this->T1) {
                state = CLOSING;
            }
            motor.write(90);
            Lcd::print("PRESS CLOSE WHEN DONE");
            break;

        case CLOSING:
            Lcd::free();
            Lcd::printForTime("WASTE RECEIVED", 3000);
            motor.write(0);
            state = CLOSED;
            this->t0 = millis();
            break;

        case CLOSED:
            if (millis() - this->t0 > this->T2) {
                Lcd::defaultMssg();
            }

            break;
    }
}

void Door::externalOn() { state = CLOSING; }