#include "WasteTask.h"

#include <Arduino.h>

#include "Lcd.h"
#include "SystemCommand.h"
#include "WasteSensorImpl.h"

WasteTask::WasteTask(int trigger, int echo, double minDist) {
    this->wasteSensor = new WasteSensorImpl(trigger, echo);
    this->minDist = minDist;
}

void WasteTask::init(int period) {
    Task::init(period);
    state = NOTFULL;
}

void WasteTask::tick() {
    if (state == NOTFULL) {
      //Serial.println(distance());
        if (isFull()) {
            state = FULL;
            SystemCommand::led1Off();
            SystemCommand::led2On();
            Lcd::free();
            Lcd::print("CONTAINER FULL");
            SystemCommand::shutDown();
        }
    }
}

bool WasteTask::isFull() { return this->wasteSensor->newDistance() < this->minDist; }

void WasteTask::clean() {
            SystemCommand::led1On();
            SystemCommand::led2Off();
    Lcd::defaultMssg();
    state = NOTFULL;
}

double WasteTask::distance() { return this->wasteSensor->lastDistance(); }