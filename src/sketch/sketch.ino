#include <Arduino.h>

#include "ButtonTask.h"
#include "Door.h"
#include "InputTask.h"
#include "Lcd.h"
#include "OutputTask.h"
#include "Scheduler.h"
#include "SystemCommand.h"
#include "TemperatureTask.h"
#include "UserSensor.h"

const int LED1PIN = 13;
const int LED2PIN = 12;
const int MOTORPIN = 9;
const int TRIGGERPIN = 7;
const int ECHOPIN = 8;
const int MOVEMENTSENSORPIN = 0;
const int TEMPSENS = A0;
const int OPENBUTTON = 6;
const int CLOSEBUTTON = 5;
const int HUMANREFLEX = 160;

Scheduler sched;

void setup() {
    Serial.begin(9600);
    Serial.setTimeout(20);
    Lcd::init();
    TemperatureTask temperatureTask = TemperatureTask(TEMPSENS);
    Door door = Door(MOTORPIN);
    WasteTask waste = WasteTask(TRIGGERPIN, ECHOPIN);
    UserSensor pir = UserSensor(MOVEMENTSENSORPIN);
    ButtonTask button = ButtonTask(OPENBUTTON, CLOSEBUTTON);
    InputTask input = InputTask();
    OutputTask output = OutputTask();

    SystemCommand::init(&temperatureTask, &waste, &door, LED1PIN, LED2PIN);

    temperatureTask.init(400);
    input.init(HUMANREFLEX);
    output.init(1000);  // the gui updates every second
    door.init(HUMANREFLEX);

    // very heavy on the program but in order to fill half a centimeter of a
    // glass with a diameter of 6 cm with a fountain you need about 0.3 seconds
    waste.init(200);

    pir.init(HUMANREFLEX);
    button.init(HUMANREFLEX);

    sched = Scheduler();
    sched.init(40);

    sched.addTask(&door);
    sched.addTask(&button);
    sched.addTask(&pir);
    sched.addTask(&temperatureTask);
    sched.addTask(&waste);
    sched.addTask(&output);
    sched.addTask(&input);

    SystemCommand::led1On();
    SystemCommand::led2Off();
    Lcd::defaultMssg();
}

void loop() { sched.schedule(); }