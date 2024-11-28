#include "Lcd.h"

#include <Arduino.h>

Lcd* Lcd::instance = nullptr;

Lcd::Lcd() {
    lcd = LiquidCrystal_I2C(0x27, 20, 4);
    lcd.init();
    lcd.backlight();
}

void Lcd::init() {
    if (instance == nullptr) {
        instance = new Lcd();
        instance->occupied = false;
    }
}

void Lcd::print(const String& message, uint8_t col, uint8_t row) {
    if (instance!=nullptr && !instance->occupied) {
        instance->occupied = true;
        lcd.clear();
        lcd.setCursor(col, row);
        lcd.print(message);
    }
}

void Lcd::printForTime(const String& message, const int T0, uint8_t col,
                       uint8_t row) {
    if (instance != nullptr && !instance->occupied) {
        instance->occupied = true;
        instance->time = millis();
        instance->T0 = T0;
        lcd.clear();
        lcd.setCursor(col, row);
        lcd.print(message);
    }
}

void Lcd::free() {
    if (instance != nullptr) {
        instance->occupied = false;
        lcd.clear();
    }
}

void Lcd::defaultMssg() {
    Lcd::free();
    lcd.setCursor(0, 0);
    lcd.print("PRESS OPEN TO ENTER WASTE");
}

bool Lcd::isOccupied() {
    if (instance->occupied) {
        if (millis() - instance->time > instance->T0) {
            Lcd::free();
        }
    }
    return instance->occupied;
}

void Lcd::simplePrint(const String& message, uint8_t col, uint8_t row) {
    lcd.setCursor(col, row);
    lcd.print(message);
}
