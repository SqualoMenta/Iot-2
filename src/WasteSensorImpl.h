#ifndef __WASTESENSIMPL__
#define __WASTESENSIMPL__

#include "WasteSensor.h"

class WasteSensorImpl : public WasteSensor {
   private:
    double oldDistance = 100;
    int pin;

   public:
    WasteSensorImpl(int pin);
    double lastDistance();
    double newDistance();  // this is the most expansive operation of the
                           // program for the call to pulseIn
};

#endif