#include "ButtonTask.h"

ButtonTask::ButtonTask(Button* openButton, Button* closeButton) {
    this->openButton = openButton;
    this->closeButton = closeButton;
}

void ButtonTask::tick() {
    if (openButton->isPressed()) {
        SystemCommand::open();
    } else if (closeButton->isPressed()) {
        SystemCommand::close();
    }
}