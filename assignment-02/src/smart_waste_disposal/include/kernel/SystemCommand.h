#ifndef __COMMANDSYS__
#define __COMMANDSYS__

#include "include/arduinoObjects/Light.h"
#include "include/task/Door.h"
#include "include/task/TemperatureTask.h"
#include "include/task/WasteTask.h"

class SystemCommand {
   private:
    static Door *door;
    static TemperatureTask *tempTask;
    static WasteTask *wasteTask;
    static Light *led1;
    static Light *led2;
    static SystemCommand *instance;
    static double maxDist;
    static double minDist;
    static bool tempProb;
    static bool full;

    SystemCommand();

   public:
    static void init(TemperatureTask *tempTask, WasteTask *WasteTask,
                     Door *door, int pinLed1, int pinLed2, double maxDist = 10,
                     double minDist = 6);
    static void close();
    static void open();
    static void wasteShutDown();
    static void tempShutDown();
    static void restore();
    static void clean();
    static void led1On();
    static void led2On();
    static void led1Off();
    static void led2Off();
    static float temperature();
    static int fullness();
};

#endif