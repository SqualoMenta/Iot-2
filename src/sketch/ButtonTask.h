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
    ButtonTask(int openButtonPin, int closeButtonPin);
    void tick();
};

#endif