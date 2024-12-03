#ifndef __BUTTONTASK__
#define __BUTTONTASK__

#include "arduinoObjects/Button.h"
#include "kernel/SystemCommand.h"
#include "task/Task.h"

class ButtonTask : public Task {
   private:
    Button* openButton;
    Button* closeButton;

   public:
    ButtonTask(int openButtonPin, int closeButtonPin);
    void tick();
};

#endif