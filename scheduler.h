#ifdef __cplusplus
extern "C" {
#endif

// Function declarations

#ifdef __cplusplus
}
#endif



#ifndef SCHEDULER_H
#define SCHEDULER_H

struct Process {
    int id;
    int arrival;
    int burst;
    int priority;
    int completion;
    int turnaround;
    int waiting;
};

void fcfs(Process processes[], int n);
void sjf(Process processes[], int n);
void roundRobin(Process processes[], int n, int timeQuantum);
void priorityScheduling(Process processes[], int n);
void displayProcesses(Process processes[], int n);

#endif
