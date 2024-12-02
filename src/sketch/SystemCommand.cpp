#include "SystemCommand.h"

#include "Led.h"

SystemCommand* SystemCommand::instance = nullptr;
TemperatureTask* SystemCommand::tempTask = nullptr;
WasteTask* SystemCommand::wasteTask = nullptr;
Door* SystemCommand::door = nullptr;
Light* SystemCommand::led1 = nullptr;
Light* SystemCommand::led2 = nullptr;
double SystemCommand::maxDist;
double SystemCommand::minDist;

SystemCommand::SystemCommand() {}

void SystemCommand::init(TemperatureTask* tempTask, WasteTask* WasteTask,
                         Door* door, int pinLed1, int pinLed2, double maxDist,
                         double minDist) {
    if (instance == nullptr) {
        instance = new SystemCommand();
        SystemCommand::tempTask = tempTask;
        SystemCommand::wasteTask = wasteTask;
        SystemCommand::door = door;
        instance->led1 = new Led(pinLed1);
        SystemCommand::led2 = new Led(pinLed2);
        SystemCommand::maxDist = maxDist;
        SystemCommand::minDist = minDist;
    }
}

void SystemCommand::close() {
    if (instance != nullptr) {
        door->close();
    }
}

void SystemCommand::open() {
    if (instance != nullptr) {
        door->open();
    }
}

void SystemCommand::shutDown() {
    if (instance != nullptr) {
        door->shutDown();
    }
}

void SystemCommand::restore() {
    if (instance != nullptr) {
        door->externalOn();
        tempTask->restore();
    }
}

void SystemCommand::clean() {
    if (instance != nullptr) {
        door->externalOn();
        wasteTask->clean();
    }
}

void SystemCommand::led1On() {
    if (instance != nullptr) {
        led1->switchOn();
    }
}

void SystemCommand::led1Off() {
    if (instance != nullptr) {
        led1->switchOff();
    }
}

void SystemCommand::led2On() {
    if (instance != nullptr) {
        led2->switchOn();
    }
}

void SystemCommand::led2Off() {
    if (instance != nullptr) {
        led2->switchOff();
    }
}

float SystemCommand::temperature() {
    if (instance != nullptr) {
        return tempTask->temperature();
    }
}

int SystemCommand::fullness() {
    if (instance != nullptr) {
        double distance = wasteTask->distance();
        if (distance > maxDist) {
            return 0;
        } else {
            return ((maxDist - distance) / (maxDist - minDist)) * 100;
        }
    }
}