#include <Arduino.h>
#include "Timer.h"
#include "Scheduler.h"

Scheduler sched;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sched.schedule();
}