#include <Arduino.h>
#include "Lcd.h"
#include "Scheduler.h"
#include "ButtonImpl.h"
#include "Door.h"
#include "ButtonTask.h"

// Oggetti globali
Scheduler sched;
LiquidCrystal_I2C lcd(0x27, 20, 4);

Door* door;
Button* openButton;
Button* closeButton;
ButtonTask* buttonTask;

void setup() {
    Serial.begin(9600);
    Lcd::init();

    //bottoni
    //door = new Door(9);
    //openButton = new ButtonImpl(2);
    //closeButton = new ButtonImpl(3);

    //buttonTask = new ButtonTask(openButton, closeButton, door);

    //sched.addTask(buttonTask);

    //door->shutDown();
}

void loop() {
    sched.schedule();
}