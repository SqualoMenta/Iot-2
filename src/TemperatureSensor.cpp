#include "TemperatureSensor.h"

#include <Arduino.h>

#include "Lcd.h"
#include "Light.h"

TemperatureSensor::TemperatureSensor(int pin, int pinLed1, int pinLed2,
                                     int pinButton, float maxTemp,
                                     float maxTempTime)
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
        if (isHot())
        {
            state = HOT;
            this->timeZero = millis();
        }
    }
    else if (state == HOT)
    {
        if (isHot())
        {
            if (millis() - this->timeZero > maxTempTime)
            {
                state = PROBLEM;
                led1->switchOff();
                led2->switchOn();
                Lcd::free();
                Lcd::print("PROBLEM DETECTED");
                SystemCommand::shutDown();
            }
        }
        else
        {
            state = OK;
        }
    }
}

float TemperatureSensor::temperature()
{
    return analogRead(pin) * (5.0 / 1023.0) * 100;
}

bool TemperatureSensor::isHot() { return this->temperature() > maxTemp; }

void TemperatureSensor::restore()
{
    Lcd::defaultMssg();
    state = OK;
}