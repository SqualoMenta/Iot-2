#ifndef __INPUTTASK__
#define __INPUTTASK__

#include "Task.h"
#include "kernel/Logger.h"

class InputTask : public Task {
   private:
    Logger log;
    String input;

   public:
    InputTask();
    void init(int period);
    void tick();
};

#endif