#include "Door.h"

Door::Door(Motor* motor, unsigned long T1, unsigned long T2) {
    this->state = CLOSING;
    this->T1 = T1;
    this->T2 = T2;
    this->motor = motor;
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
    motor->close();
    state = OFF;
}

void Door::tick() {
    switch (state) {
        case OPENING:
            motor->open();
            state = OPEN;
            Lcd::print("PRESS CLOSE WHEN DONE");
            break;

        case OPEN:
            if (millis() - this->t0 > this->T1){
                state = CLOSING;
            }
            break;

        case CLOSING:
            Lcd::free();
            Lcd::printForTime("WASTE RECEIVED", 3000);
            motor->close();
            state = CLOSED;
            this->t0 = millis();
            break;

        case CLOSED:
            if (millis() - this->t0 > this->T2) {
                Lcd::defaultMssg();
                state = NOMESSAGE;
            }

            break;
    }
}

void Door::externalOn() { state = NOMESSAGE; }