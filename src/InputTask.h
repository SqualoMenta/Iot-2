#ifndef __INPUTTASK__
#define __INPUTTASK__

#include "Task.h"
#include "kernel/Logger.h"

class InputTask : public Task {
   private:
    Logger log;
    String input;

   public:
    void tick();
};

#endif