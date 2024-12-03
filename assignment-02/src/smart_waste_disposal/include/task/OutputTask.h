#ifndef __OUTPUTTASK__
#define __OUTPUTTASK__

#include "include/kernel/Logger.h"
#include "include/task/Task.h"

class OutputTask : public Task {
   private:
    Logger log;

   public:
    void tick();
};

#endif