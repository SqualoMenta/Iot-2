#ifndef __BUTTONTASK__
#define __BUTTONTASK__

#include "Button.h"
#include "SystemCommand.h"
#include "Task.h"

class ButtonTask : public Task {
   private:
    Button* openButton;
    Button* closeButton;

   public:
    ButtonTask(Button* openButton, Button* closeButton);
    void tick();
};

#endif