#include "include/task/InputTask.h"

#include "include/kernel/SystemCommand.h"

void InputTask::tick() {
    input = log.getMsg();
    if (input == "CLEAN") {
        // Serial.println("here");
        SystemCommand::clean();
    }
    if (input == "RESTORE") {
        SystemCommand::restore();
    }
}