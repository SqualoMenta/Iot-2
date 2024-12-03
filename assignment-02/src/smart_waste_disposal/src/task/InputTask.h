#ifndef __INPUTTASK__
#define __INPUTTASK__

#include "kernel/Logger.h"
#include "task/Task.h"

class InputTask : public Task {
   private:
    Logger log;
    String input;

   public:
    void tick();
};

#endif