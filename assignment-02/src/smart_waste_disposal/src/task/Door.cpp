#include "task/Door.h"

#include "arduinoObjects/Lcd.h"
#include "arduinoObjects/MotorImpl.h"

#define WASTETIME 3000

Door::Door(int pin, unsigned long T1, unsigned long T2) {
    this->state = CLOSED;
    this->timer1.setupPeriod(T1);
    this->timer2.setupPeriod(T2);
    this->motor = new MotorImpl(pin);
}

void Door::open() {
    if (state != OFF && state != CLOSING) {
        state = OPENING;
        this->timer1.resetTimer();
    }
}

void Door::close() {
    if (state == OPEN) {
        state = CLOSING;
    }
}

void Door::shutDown() {
    motor->close();
    state = OFF;
}

void Door::tick() {
    // static int i;
    // Serial.println(i++);
    switch (state) {
        case OPENING:
            motor->open();
            state = OPEN;
            Lcd::print("PRESS CLOSE WHEN DONE");
            break;

        case OPEN:
            if (this->timer1.isPeriodPassed()) {
                // Serial.print("Yep");
                state = CLOSING;
            }
            break;

        case CLOSING:
            Lcd::free();
            Lcd::printForTime("WASTE RECEIVED", WASTETIME);
            motor->close();
            state = CLOSED;
            this->timer2.resetTimer();
            break;

        case CLOSED:
            if (this->timer2.isPeriodPassed()) {
                Lcd::defaultMssg();
                state = NOMESSAGE;
            }

            break;
    }
}

void Door::externalOn() { state = NOMESSAGE; }