#ifndef __OUTPUTTASK__
#define __OUTPUTTASK__

#include "kernel/Logger.h"
#include "task/Task.h"

class OutputTask : public Task {
   private:
    Logger log;

   public:
    void tick();
};

#endif