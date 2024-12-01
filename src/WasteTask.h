#ifndef __WASTETASK__
#define __WASTETASK__

#include "Task.h"
#include "WasteSensor.h"

class WasteTask : public Task {
   private:
    WasteSensor* wasteSensor;
    double minDist;

    enum { FULL, NOTFULL } state;

    bool isFull();

   public:
    WasteTask(int trigger, int echo, double minDist = 1);
    void init(int period);
    void tick();
    void clean();
    double distance();
};

#endif