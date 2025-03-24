#include <iostream>
#include <algorithm>  // For sorting in SJF & Priority Scheduling
#include "scheduler.h"
#include <vector>
#include <queue>

using namespace std;

// Function to display the process table
void displayProcesses(Process processes[], int n) {
    cout << "\nProcess Table:\n";
    cout << "ID\tArrival\tBurst\tPriority\tCompletion\tTurnaround\tWaiting\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].id << "\t" 
             << processes[i].arrival << "\t" 
             << processes[i].burst << "\t" 
             << processes[i].priority << "\t\t" 
             << processes[i].completion << "\t\t" 
             << processes[i].turnaround << "\t\t" 
             << processes[i].waiting << "\n";
    }
}

// **FCFS Scheduling**
void fcfs(Process processes[], int n) {
    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time < processes[i].arrival) {
            time = processes[i].arrival; // Wait until the process arrives
        }
        time += processes[i].burst;
        processes[i].completion = time;
        processes[i].turnaround = processes[i].completion - processes[i].arrival;
        processes[i].waiting = processes[i].turnaround - processes[i].burst;
    }
}

// **SJF Scheduling (Non-Preemptive)**
void sjf(Process processes[], int n) {
    sort(processes, processes + n, [](Process a, Process b) {
        if (a.burst == b.burst) 
            return a.arrival < b.arrival; // Prioritize earlier arrival if burst time is same
        return a.burst < b.burst;
    });
    fcfs(processes, n);  // Use FCFS logic after sorting
}

// **Round Robin Scheduling**
void roundRobin(Process processes[], int n, int timeQuantum) {
    queue<int> q;
    int time = 0; 
    vector<int> remainingBurst(n);
    vector<bool> completed(n, false); // Track completed processes

    for (int i = 0; i < n; i++) {
        remainingBurst[i] = processes[i].burst;
    }

    // Initially enqueue processes that have arrived
    for (int i = 0; i < n; i++) {
        if (processes[i].arrival == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int i = q.front();
        q.pop();

        if (remainingBurst[i] > timeQuantum) {
            time += timeQuantum;
            remainingBurst[i] -= timeQuantum;

            // Add new processes that arrived during this time
            for (int j = 0; j < n; j++) {
                if (!completed[j] && processes[j].arrival > time - timeQuantum && processes[j].arrival <= time) {
                    q.push(j);
                }
            }

            q.push(i); // Re-add unfinished process
        } else {
            time += remainingBurst[i];
            processes[i].completion = time;
            processes[i].turnaround = processes[i].completion - processes[i].arrival;
            processes[i].waiting = processes[i].turnaround - processes[i].burst;
            remainingBurst[i] = 0;
            completed[i] = true;
        }
    }
}

// **Priority Scheduling (Non-Preemptive)**
void priorityScheduling(Process processes[], int n) {
    sort(processes, processes + n, [](Process a, Process b) {
        if (a.priority == b.priority)
            return a.arrival < b.arrival; // Prioritize earlier arrival
        return a.priority < b.priority;
    });
    fcfs(processes, n);  // Use FCFS logic after sorting
}
