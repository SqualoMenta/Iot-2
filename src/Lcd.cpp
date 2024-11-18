#include <LiquidCrystal_I2C.h>
#include "Lcd.h"

Lcd ::Lcd() : lcd(0x27, 20, 4) {
}

void Lcd::print(String msg){
    //Serial.println(msg);
    lcd.clear();
    lcd.print(msg);
}
