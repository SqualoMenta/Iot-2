#include "SystemCommand.h"

SystemCommand* SystemCommand::instance = nullptr;
TemperatureSensor* SystemCommand::tempSens = nullptr;
WasteSensor* SystemCommand::wasteSens = nullptr;
Door* SystemCommand::door = nullptr;

SystemCommand::SystemCommand() {}

void SystemCommand::init(TemperatureSensor* tempSens, WasteSensor* WasteSensor,
                         Door* door) {
    if (instance == nullptr) {
        instance = new SystemCommand();
        instance->tempSens = tempSens;
        instance->wasteSens = wasteSens;
        instance->door = door;
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
        instance->tempSens->restore();
    }
}

void SystemCommand::clean() {
    if (instance != nullptr) {
        instance->wasteSens->clean();
    }
}
