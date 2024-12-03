#include "ButtonTask.h"
#include "ButtonImpl.h"

ButtonTask::ButtonTask(int openButtonPin, int closeButtonPin) {
    this->openButton = new ButtonImpl(openButtonPin);
    this->closeButton = new ButtonImpl(closeButtonPin);
}

void ButtonTask::tick() {
  //Serial.println("Here");
    if (openButton->isPressed()) {
      //Serial.println("Here");
        SystemCommand::open();
    } else if (closeButton->isPressed()) {
      //Serial.print("me");
        SystemCommand::close();
    }
}