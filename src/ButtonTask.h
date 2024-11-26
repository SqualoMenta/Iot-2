#ifndef __BUTTONTASK__
#define __BUTTONTASK__

#include "Task.h"
#include "Button.h"
#include "Door.h"

class ButtonTask : public Task {
private:
    Button* openButton;
    Button* closeButton;
    Door* door;

public:
    ButtonTask(Button* openButton, Button* closeButton, Door* door);
    void tick();
};

#endif