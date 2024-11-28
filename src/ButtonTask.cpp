#include "ButtonTask.h"
#include "ButtonImpl.h"

ButtonTask::ButtonTask(int openButtonPin, int closeButtonPin) {
    this->openButton = new ButtonImpl(openButtonPin);
    this->closeButton = new ButtonImpl(closeButtonPin);
}

void ButtonTask::tick() {
    if (openButton->isPressed()) {
        SystemCommand::open();
    } else if (closeButton->isPressed()) {
        SystemCommand::close();
    }
}