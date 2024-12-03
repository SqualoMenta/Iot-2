#include "kernel/SystemCommand.h"

#include "arduinoObjects/Led.h"

SystemCommand* SystemCommand::instance = nullptr;
TemperatureTask* SystemCommand::tempTask = nullptr;
WasteTask* SystemCommand::wasteTask = nullptr;
Door* SystemCommand::door = nullptr;
Light* SystemCommand::led1 = nullptr;
Light* SystemCommand::led2 = nullptr;
double SystemCommand::maxDist;
double SystemCommand::minDist;
bool SystemCommand::full = false;
bool SystemCommand::tempProb = false;

SystemCommand::SystemCommand() {}

void SystemCommand::init(TemperatureTask* tempTask, WasteTask* wasteTask,
                         Door* door, int pinLed1, int pinLed2, double maxDist,
                         double minDist) {
    if (instance == nullptr) {
        instance = new SystemCommand();
        SystemCommand::tempTask = tempTask;
        SystemCommand::wasteTask = wasteTask;
        SystemCommand::door = door;
        SystemCommand::led1 = new Led(pinLed1);
        SystemCommand::led2 = new Led(pinLed2);
        SystemCommand::maxDist = maxDist;
        SystemCommand::minDist = minDist;
    }
}

void SystemCommand::close() {
    if (instance != nullptr) {
        // Serial.println("here");
        door->close();
    }
}

void SystemCommand::open() {
    if (instance != nullptr) {
        door->open();
    }
}

void SystemCommand::tempShutDown() {
    if (instance != nullptr) {
        tempProb = true;
        door->shutDown();
    }
}

void SystemCommand::wasteShutDown() {
    if (instance != nullptr) {
        full = true;
        door->shutDown();
    }
}

void SystemCommand::restore() {
    if (instance != nullptr) {
        tempProb = false;
        if (!full) {
            door->externalOn();
        }
        tempTask->restore();
    }
}

void SystemCommand::clean() {
    if (instance != nullptr) {
        full = false;
        if (!tempProb) {
            door->externalOn();
        }
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
        // Serial.println(distance);
        if (distance < maxDist) {
            return ((maxDist - distance) / (maxDist - minDist)) * 100;
        }
    }
    return 0;
}