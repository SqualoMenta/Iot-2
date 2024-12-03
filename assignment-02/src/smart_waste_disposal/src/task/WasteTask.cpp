#include "include/task/WasteTask.h"

#include "include/arduinoObjects/Lcd.h"
#include "include/arduinoObjects/WasteSensorImpl.h"
#include "include/kernel/SystemCommand.h"

WasteTask::WasteTask(int trigger, int echo, double minDist) {
    this->wasteSensor = new WasteSensorImpl(trigger, echo);
    this->minDist = minDist;
}

void WasteTask::init(int period) {
    Task::init(period);
    state = NOTFULL;
}

void WasteTask::tick() {  // Serial.println(distance());
    if (state == NOTFULL) {
        if (isFull()) {
            state = FULL;
            SystemCommand::led1Off();
            SystemCommand::led2On();
            Lcd::free();
            Lcd::print("CONTAINER FULL");
            SystemCommand::wasteShutDown();
        }
    }
}

bool WasteTask::isFull() {
    return this->wasteSensor->newDistance() < this->minDist;
}

void WasteTask::clean() {
    SystemCommand::led1On();
    SystemCommand::led2Off();
    Lcd::defaultMssg();
    state = NOTFULL;
}

double WasteTask::distance() { return this->wasteSensor->lastDistance(); }