#ifndef __LOGGER__
#define __LOGGER__

#include <Arduino.h>

class Logger {
   private:
    const String OUT = "OUT::";
    const String IN = "IN::";

   public:
    void sendMsg(String msg);
    void sendMsg(float temp);
    void sendMsg(int fullness);
    String getMsg();
};

#endif