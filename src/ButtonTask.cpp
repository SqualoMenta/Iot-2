#include "ButtonTask.h"

ButtonTask::ButtonTask(Button* openButton, Button* closeButton, Door* door) {
    this->openButton = openButton;
    this->closeButton = closeButton;
    this->door = door;
}

void ButtonTask::tick() {
    if (openButton->isPressed()) {
        door->open();
    } else if (closeButton->isPressed()) {
        door->close();
    }
}