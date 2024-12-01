#include "InputTask.h"

#include "SystemCommand.h"

void InputTask::tick() {
    input = log.getMsg();
    if (input == "CLEAN") {
        SystemCommand::clean();
    }
    if (input == "RESTORE") {
        SystemCommand::restore();
    }
}