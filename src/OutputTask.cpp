#include "OutputTask.h"
#include "SystemCommand.h"

void OutputTask::tick() {
    float temp = SystemCommand::temperature();
    int fullness = SystemCommand::fullness();
    temp = round(temp * 100) / 100.0; // we keep at most 2 decimals
    log.sendMsg(temp);
    log.sendMsg(fullness);
}