#ifndef __USERTASK__
#define __USERTASK__

#include "Task.h"
#include "Timer.h"

class UserSensor : public Task {
   private:
    int output;
    Timer timer;
    static UserSensor* instance;

    enum { ACTIVE, FAR, AFK } state;
    static void onInterrupt();
    bool isFar();

   public:
    UserSensor(int output, float tSleep = 100000);
    void init(int period);
    void tick();
};

#endif