#include "LcdTask.h"
#include "Lcd.h"

void LcdTask::tick(){
    if(!Lcd::isOccupied()){
        Lcd::simplePrint("PRESS OPEN TO ENTER WASTE");
    }
}