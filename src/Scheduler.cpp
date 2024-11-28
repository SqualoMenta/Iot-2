#include "Scheduler.h"

volatile bool timerFlag;
Timer timer;

void timerHandler(void) { timerFlag = true; }

void Scheduler::init(int basePeriod) {
    this->basePeriod = basePeriod;
    long period = 1000l * basePeriod;
    timer.setupPeriod(period);
    nTasks = 0;
}

bool Scheduler::addTask(Task* task) {
    if (nTasks < MAX_TASKS - 1) {
        taskList[nTasks] = task;
        nTasks++;
        return true;
    } else {
        return false;
    }
}

void Scheduler::schedule() {
    timer.waitForNextTick();

    for (int i = 0; i < nTasks; i++) {
        if (taskList[i]->updateAndCheckTime(basePeriod)) {
            taskList[i]->tick();
        }
    }
}
