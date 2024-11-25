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
    if (state != OFF) {
        state = CLOSING;
    }
}

void Door::shutDown() {
    motor.write(0);
    state = OFF;
}

void Door::tick() {
    if (millis() - this->t0 > this->maxTime) {
        state = CLOSING;
    }
    
    switch (state) {
        case OPENING:
            motor.write(90);
            Lcd::print("PRESS CLOSE WHEN DONE");
            break;

        case CLOSING:
            Lcd::free();
            Lcd::printForTime("WASTE RECEIVED", 3000);
            motor.write(0);
            break;
    }
}

void Door::externalOn() { state = CLOSING; }