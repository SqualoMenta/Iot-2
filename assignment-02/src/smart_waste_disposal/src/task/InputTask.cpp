#include "task/InputTask.h"

#include "kernel/SystemCommand.h"

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