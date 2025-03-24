#include <iostream>
#include "ganttchart.h"

using namespace std;

void displayGanttChart(Process processes[], int n) {
    cout << "\nGantt Chart:\n";

    // Print the top bar
    cout << " ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < processes[i].burst; j++)
            cout << "--";
        cout << " ";
    }
    cout << "\n|";

    // Print process sequence
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < processes[i].burst - 1; j++)
            cout << " ";
        cout << "P" << processes[i].id;
        for (int j = 0; j < processes[i].burst - 1; j++)
            cout << " ";
        cout << "|";
    }
    cout << "\n ";

    // Print the bottom bar
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < processes[i].burst; j++)
            cout << "--";
        cout << " ";
    }
    cout << "\n";

    // Print time values
    cout << "0";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < processes[i].burst; j++)
            cout << "  ";
        cout << processes[i].completion;
    }
    cout << "\n";
}
