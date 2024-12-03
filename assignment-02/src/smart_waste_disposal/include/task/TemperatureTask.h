#ifndef __TEMPERATURETASK__
#define __TEMPERATURETASK__

#include "include/kernel/Logger.h"
#include "include/kernel/Timer.h"
#include "include/task/Task.h"

class TemperatureTask : public Task {
   private:
    int pin;
    float maxTemp;
    const float BETA = 3950;
    Timer timer;
    Logger prSender;

    enum { OK, HOT, PROBLEM } state;

    bool isHot();

   public:
    TemperatureTask(int pin, float maxTemp = 24,
                    unsigned long maxTempTime = 5000);
    void init(int period);
    void tick();
    float temperature();
    void restore();
};

#endif