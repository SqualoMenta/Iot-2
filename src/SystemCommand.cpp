#include "SystemCommand.h"

#include "Led.h"

SystemCommand* SystemCommand::instance = nullptr;
TemperatureTask* SystemCommand::tempTask = nullptr;
WasteTask* SystemCommand::wasteTask = nullptr;
Door* SystemCommand::door = nullptr;

SystemCommand::SystemCommand() {}

void SystemCommand::init(TemperatureTask* tempTask, WasteTask* WasteTask,
                         Door* door, int pinLed1, int pinLed2, double maxDist,
                         double minDist) {
    if (instance == nullptr) {
        instance = new SystemCommand();
        instance->tempTask = tempTask;
        instance->wasteTask = wasteTask;
        instance->door = door;
        instance->led1 = new Led(pinLed1);
        instance->led2 = new Led(pinLed2);
        instance->maxDist = maxDist;
        instance->minDist = minDist;
    }
}

void SystemCommand::close() {
    if (instance != nullptr) {
        instance->door->close();
    }
}

void SystemCommand::open() {
    if (instance != nullptr) {
        instance->door->open();
    }
}

void SystemCommand::shutDown() {
    if (instance != nullptr) {
        instance->door->shutDown();
    }
}

void SystemCommand::externalOn() {
    if (instance != nullptr) {
        instance->door->externalOn();
    }
}

void SystemCommand::restore() {
    if (instance != nullptr) {
        instance->tempTask->restore();
    }
}

void SystemCommand::clean() {
    if (instance != nullptr) {
        instance->wasteTask->clean();
    }
}

void SystemCommand::led1On() { instance->led1->switchOn(); }

void SystemCommand::led1Off() { instance->led1->switchOff(); }

void SystemCommand::led2On() { instance->led2->switchOn(); }

void SystemCommand::led2Off() { instance->led2->switchOff(); }

float SystemCommand::temperature() { return tempTask->temperature(); }

int SystemCommand::fullness() {
    double distance = wasteTask->distance();
    if (distance > maxDist) {
        return 0;
    } else {
        return ((maxDist - distance) / (maxDist - minDist)) * 100;
    }
}