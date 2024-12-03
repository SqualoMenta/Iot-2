#include "include/task/TemperatureTask.h"

#include "include/arduinoObjects/Lcd.h"
#include "include/arduinoObjects/Light.h"
#include "include/kernel/SystemCommand.h"

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
    // Serial.println(temperature());
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
                SystemCommand::tempShutDown();
            }
        } else {
            state = OK;
        }
    }
}

float TemperatureTask::temperature() {
    return ((analogRead(pin) / 1024.0 * 5.0) - 0.5) * 100;
}

bool TemperatureTask::isHot() { return this->temperature() > maxTemp; }

void TemperatureTask::restore() {
    SystemCommand::led1On();
    SystemCommand::led2Off();
    Lcd::defaultMssg();
    state = OK;
}
