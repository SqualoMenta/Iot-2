#include "WasteSensor.h"

#include "Light.h"

WasteSensor::WasteSensor(int input, int output)
{
    this->input = input;
    this->output = output;
}

void WasteSensor::init(int period)
{
    Task::init(period);
    state = NOTFULL;
}

void WasteSensor::tick()
{
    if(state==NOTFULL){
        if(isFull()){
            state = FULL;
        }else{

        }
    }
}