#ifndef __COMMANDSYS__
#define __COMMANDSYS__

#include "Door.h"
#include "TemperatureSensor.h"
#include "WasteSensor.h"

class SystemCommand
{
private:
    static Door *door;
    static TemperatureSensor *tempSens;
    static WasteSensor *wasteSens;
    static SystemCommand *instance;
    static Light *led1;
    static Light *led2;

    SystemCommand();

public:
    static void init(TemperatureSensor *tempSens, WasteSensor *WasteSensor,
                     Door *door, Light *led1, Light *led2);
    static void close();
    static void open();
    static void shutDown();
    static void externalOn();
    static void restore();
    static void clean();
};

#endif