#include "Lcd.h"

#include <Arduino.h>

Lcd* Lcd::instance = nullptr;
LiquidCrystal_I2C Lcd::lcd = LiquidCrystal_I2C(0x27, 20, 4);
Timer Lcd::timer;
bool Lcd::occupied;

Lcd::Lcd() {
    lcd.init();
    lcd.backlight();
}

void Lcd::init() {
    if (instance == nullptr) {
        instance = new Lcd();
        occupied = false;
    }
}

void Lcd::print(const String& message, uint8_t col, uint8_t row) {
    if (instance != nullptr && !occupied) {
        instance->occupied = true;
        lcd.clear();
        lcd.setCursor(col, row);
        lcd.print(message);
    }
}

void Lcd::printForTime(const String& message, const int T0, uint8_t col,
                       uint8_t row) {
    if (instance != nullptr && !occupied) {
        occupied = true;
        timer.setupPeriod(T0);
        timer.resetTimer();
        lcd.clear();
        lcd.setCursor(col, row);
        lcd.print(message);
    }
}

void Lcd::free() {
    if (instance != nullptr) {
        occupied = false;
        lcd.clear();
    }
}

void Lcd::defaultMssg() {
    if (instance != nullptr) {
        Lcd::free();
        lcd.setCursor(0, 0);
        lcd.print("PRESS OPEN TO \nENTER WASTE");
    }
}

bool Lcd::isOccupied() {
    if (instance != nullptr) {
        if (occupied) {
            if (timer.isPeriodPassed()) {
                Lcd::free();
            }
        }
        return occupied;
    }
}

void Lcd::simplePrint(const String& message, uint8_t col, uint8_t row) {
    if (instance != nullptr) {
        lcd.setCursor(col, row);
        lcd.print(message);
    }
}
