#include "OutputTask.h"
#include "SystemCommand.h"

#include "Arduino.h"

void OutputTask::tick() {
  //Serial.println("ciao");
    float temp = SystemCommand::temperature();
    int fullness = SystemCommand::fullness();
    temp = round(temp * 100) / 100.0; // we keep at most 2 decimals
    log.sendMsg(temp);
    log.sendMsg(fullness);
}