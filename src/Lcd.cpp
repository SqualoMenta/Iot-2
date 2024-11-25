#include "Lcd.h"

Lcd* Lcd::instance = nullptr;
LiquidCrystal_I2C* Lcd::lcd = nullptr;

Lcd::Lcd() {
    lcd = new LiquidCrystal_I2C(0x27, 20, 4);
    lcd->init();
    lcd->backlight();
}

Lcd* Lcd::getInstance() {
    if (instance == nullptr) {
        instance = new Lcd();
    }
    return instance;
}

void Lcd::print(const String& message, uint8_t col, uint8_t row) {
    if (lcd) {
        lcd->clear();
        lcd->setCursor(col, row);
        lcd->print(message);
    }
}

void Lcd::clear() {
    if (lcd) {
        lcd->clear();
    }
}
