#ifndef __WASTESENSIMPL__
#define __WASTESENSIMPL__

#include "include/arduinoObjects/WasteSensor.h"

class WasteSensorImpl : public WasteSensor {
   private:
    double oldDistance = 20;
    int echo;
    int trigger;

   public:
    WasteSensorImpl(int trigger, int echo);
    double lastDistance();
    double newDistance();  // this is the most expansive operation of the
                           // program for the call to pulseIn
};

#endif