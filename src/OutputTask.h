#ifndef __OUTPUTTASK__
#define __OUTPUTTASK__

#include "Task.h"
#include "kernel/Logger.h"

class OutputTask : public Task {
   private:
    Logger log;

   public:
    void tick();
};

#endif