#ifndef LCD_H
#define LCD_H

#include <Arduino.h>

class Lcd {
   private:
    static Lcd* instance;
    static LiquidCrystal_I2C* lcd;

    Lcd();

   public:
    static Lcd* getInstance();

    static void print(const String& message, uint8_t col = 0, uint8_t row = 0);

    static void clear();
};

#endif  // LCD_H
