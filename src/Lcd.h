#ifndef __LCD__
#define __LCD__

#include <LiquidCrystal_I2C.h>

class Lcd{
   public:
    Lcd();
    void print(String msg);

    private:
     LiquidCrystal_I2C lcd;

};

#endif