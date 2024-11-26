#ifndef LCD_H
#define LCD_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#include "Task.h"

class Lcd {
   private:
    static Lcd* instance;
    static LiquidCrystal_I2C* lcd;
    static int time;
    static int T0;
    static bool occupied;

    Lcd();

   public:
    static void init();
    static void print(const String& message, uint8_t col = 0, uint8_t row = 0);
    static void free();
    static bool isOccupied();
    static void printForTime(const String& message, const int T0,
                             uint8_t col = 0, uint8_t row = 0);
    static void simplePrint(const String& message, uint8_t col = 0,
                            uint8_t row = 0);
    static void defaultMssg();
};

#endif  // LCD_H
