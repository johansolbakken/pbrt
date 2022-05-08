//
// Created by Johan Solbakken on 07/05/2022.
//

#ifndef PBRT_PARALLEL_H
#define PBRT_PARALLEL_H

#include <memory>

void TasksInit();
void TasksCleanup();

class Task {
public:
    virtual ~Task() = default;;
    virtual void Run() = 0;
};

void EnqueueTasks(const std::vector<Task*> & tasks);
void WaitForAllTasks();
int NumSystemCores();


#endif //PBRT_PARALLEL_H
