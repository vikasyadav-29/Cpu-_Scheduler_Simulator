#include <iostream>
#include "scheduler.h"

using namespace std;

int main() {
    int n, choice, quantum;
    
    cout << "Enter the number of processes: ";
    cin >> n;

    Process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "Enter arrival time, burst time, and priority for process " << i + 1 << ": ";
        cin >> processes[i].arrival >> processes[i].burst >> processes[i].priority;
    }

    while (true) {
        cout << "\nCPU Scheduling Algorithms:\n";
        cout << "1. FCFS\n";
        cout << "2. SJF\n";
        cout << "3. Round Robin\n";
        cout << "4. Priority Scheduling\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                fcfs(processes, n);
                displayProcesses(processes, n);
                break;
            case 2:
                sjf(processes, n);
                displayProcesses(processes, n);
                break;
            case 3:
                cout << "Enter time quantum: ";
                cin >> quantum;
                roundRobin(processes, n, quantum);
                displayProcesses(processes, n);
                break;
            case 4:
                priorityScheduling(processes, n);
                displayProcesses(processes, n);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
