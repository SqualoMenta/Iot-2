#include "TemperatureTask.h"

#include <Arduino.h>

#include "Lcd.h"
#include "Light.h"
#include "SystemCommand.h"

TemperatureTask::TemperatureTask(int pin, float maxTemp,
                                 unsigned long maxTempTime) {
    this->timer.setupPeriod(maxTempTime);
    this->pin = pin;
    this->maxTemp = maxTemp;
}

void TemperatureTask::init(int period) {
    Task::init(period);
    state = OK;
}

void TemperatureTask::tick() {
    Serial.println(temperature());
    if (state == OK) {
        if (isHot()) {
            state = HOT;
            this->timer.resetTimer();
        }
    } else if (state == HOT) {
        if (isHot()) {
            if (this->timer.isPeriodPassed()) {
                state = PROBLEM;
                SystemCommand::led1Off();
                SystemCommand::led2On();
                Lcd::free();
                Lcd::print("PROBLEM DETECTED");
                prSender.sendMsg("P");
                SystemCommand::shutDown();
            }
        } else {
            state = OK;
        }
    }
}

float TemperatureTask::temperature() {
    return ((analogRead(pin)/1024.0 *5.0)-0.5)*100;
}

bool TemperatureTask::isHot() { return this->temperature() > maxTemp; }

void TemperatureTask::restore() {
    Lcd::defaultMssg();
    state = OK;
}
