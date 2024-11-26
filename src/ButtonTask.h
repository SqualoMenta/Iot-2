#ifndef __BUTTONTASK__
#define __BUTTONTASK__

#include "Button.h"
#include "Door.h"
#include "Task.h"

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