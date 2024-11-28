#ifndef __WASTETASK__
#define __WASATETASK__

#include "Task.h"
#include "WasteSensor.h"

class WasteTask : public Task {
   private:
    WasteSensor* wasteSensor;
    double minDist;

    enum { FULL, NOTFULL } state;

    bool isFull();

   public:
    WasteTask(int pin, double minDist = 1);
    void init(int period);
    void tick();
    void clean();
    double distance();
};

#endif