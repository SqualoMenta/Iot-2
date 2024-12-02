#ifndef __WASTESENS__
#define __WASTESENS__

class WasteSensor {
   public:
    virtual double lastDistance();
    virtual double newDistance();  // This is a very long method
};

#endif