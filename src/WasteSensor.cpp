#include "WasteSensor.h"

WasteSensor::WasteSensor(int input, int output, int pinLed1, int pinLed2) {
    this->input = input;
    this->output = output;
    this->pinLed1 = pinLed1;
    this->pinLed2 = pinLed2;
}

void WasteSensor::init(int period) {
    Task::init(period);
    led1 = new Led(pinLed1);
    led2 = new Led(pinLed2);
    state = NOTFULL;
    led1->switchOn();
    led2->switchOff();
    pinMode(output, OUTPUT);
    pinMode(input, INPUT);
}

void WasteSensor::tick() {
    if (state == NOTFULL) {
        if (isFull()) {
            state = FULL;
            led1->switchOff();
            led2->switchOn();
            Lcd::free();
            Lcd::print("CONTAINER FULL");
            SystemCommand::shutDown();
        }
    }
}

bool WasteSensor::isFull() {
    long duration;
    float distance;

    // Invio dell'impulso ultrasonico
    digitalWrite(output, LOW);
    delayMicroseconds(2);
    digitalWrite(output, HIGH);
    delayMicroseconds(10);
    digitalWrite(output, LOW);

    // Lettura del segnale di ritorno
    duration = pulseIn(input, HIGH);

    // Calcolo della distanza
    distance = (duration * 0.034) / 2;  // 0.034 cm/µs è la velocità del suono

    return distance < 1;
}

void WasteSensor::clean() {
    Lcd::defaultMssg();
    state = NOTFULL;
}