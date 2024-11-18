#include <Arduino.h>
#include "TemperatureSensor.h"
#include "Light.h"

TemperatureSensor::TemperatureSensor(int pin, int pinLed1, int pinLed2, int pinButton, float maxTemp, float maxTempTime)
{
    this->pin = pin;
    this->pinLed1 = pinLed1;
    this->pinLed2 = pinLed2;
    this->pinButton = pinButton;
    this->maxTemp = maxTemp;
}

void TemperatureSensor::init(int period)
{
    Task::init(period);
    led1 = new Led(pinLed1);
    led2 = new Led(pinLed2);
    state = OK;
    led1->switchOn();
    led2->switchOff();
}

void TemperatureSensor::tick()
{
    if (state == OK)
    {
        if (isHot(pin, maxTemp))
        {
            state = HOT;
            this->timeZero = millis();
        }
    }else if(state == HOT){
        if(millis()-this->timeZero>maxTempTime){
            state = PROBLEM;
            led1->switchOff();
            led2->switchOn();
        }
    }
}

bool isHot(int pin, float maxTemp)
{
    int valoreAnalogico = analogRead(pin);         // Legge il valore analogico
    float temperatura = valoreAnalogico * (5.0 / 1023.0) * 100; // Conversione in °C
    return temperatura > maxTemp;
}