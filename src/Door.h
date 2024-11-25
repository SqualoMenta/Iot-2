#ifndef DOOR_H
#define DOOR_H

#include <Arduino.h>

class Lcd {
   private:
    enum { OPENING, CLOSING } state;

   public:
    static Lcd* getInstance();

    static void open();

    static void close();
};

#endif 
