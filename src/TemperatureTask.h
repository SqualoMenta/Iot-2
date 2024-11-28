#ifndef __TEMPERATURETASK__
#define __TEMPERATURETASK__

#include "Task.h"
#include "Timer.h"

class TemperatureTask : public Task {
   private:
    int pin;
    float maxTemp;
    Timer timer;

    enum { OK, HOT, PROBLEM } state;

    bool isHot();

   public:
    TemperatureTask(int pin, float maxTemp = 36,
                    unsigned long maxTempTime = 10000);
    void init(int period);
    void tick();
    float temperature();
    void restore();
};

#endif