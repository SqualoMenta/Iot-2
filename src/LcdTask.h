#ifndef __LCDTASK__
#define __LCDTASK__

#include "Task.h"

class LcdTask : public Task{
    public:
     void init(int period);
     void tick();
};

#endif