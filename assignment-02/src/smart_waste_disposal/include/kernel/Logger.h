#ifndef __LOGGER__
#define __LOGGER__

#include <Arduino.h>

#define OUT "OUT::"
#define IN "IN::"
#define IN_LENGTH 4

class Logger {
   public:
    void sendMsg(String msg);
    void sendMsg(float temp);
    void sendMsg(int fullness);
    String getMsg();
};

#endif