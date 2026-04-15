#include <iostream>
#include <vector>
#include "packet.h"
#include "scheduler.h"
#include "metrics.h"
#include <algorithm>

using namespace std;

void printGanttChart(vector<Packet> packets) {

    // sort packets by start time
    sort(packets.begin(), packets.end(), [](const Packet& a, const Packet& b) {
        return a.startTime < b.startTime;
    });

    vector<int> timeline;

    for (const auto& p : packets) {
        for (int t = p.startTime; t < p.finishTime; t++) {
            timeline.push_back(p.id);
        }
    }

    cout << "\nGantt Chart:\n";

    // blocks
    for (int id : timeline) {
        cout << "| P" << id << " ";
    }
    cout << "|\n";

    // time axis
    for (int i = 0; i <= timeline.size(); i++) {
        cout << i << "    ";
    }
    cout << endl;
}

void printResults(const vector<Packet>& packets, const string& title) {
    cout << "\n" << title << " Results:\n";
    cout << "ID\tArrival\tService\tPriority\tStart\tFinish\tWaiting\tTurnaround\n";

    for (const auto& p : packets) {
        cout << p.id << "\t"
             << p.arrivalTime << "\t"
             << p.serviceTime << "\t"
             << p.priority << "\t\t"
             << p.startTime << "\t"
             << p.finishTime << "\t"
             << p.waitingTime << "\t"
             << p.turnaroundTime << endl;
    }

    cout << "\nAverage Waiting Time: " << averageWaitingTime(packets) << endl;
    cout << "Average Turnaround Time: " << averageTurnaroundTime(packets) << endl;
    printGanttChart(packets);
}


int main() {
    vector<Packet> packets;

int n;
cout << "Enter number of packets: ";
cin >> n;

for (int i = 0; i < n; i++) {
    int arrival, service, priority;

    cout << "\nPacket " << i + 1 << ":\n";

    cout << "Arrival Time: ";
    cin >> arrival;

    cout << "Service Time: ";
    cin >> service;

    cout << "Priority: ";
    cin >> priority;

    packets.push_back(Packet(i + 1, arrival, service, priority));
}

    int choice;
    cout << "Choose Scheduling Algorithm:\n";
    cout << "1. FIFO\n";
    cout << "2. Priority Scheduling\n";
    cout << "3. Compare Both\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
    runFIFO(packets);
    printResults(packets, "FIFO Scheduling");
    
}
else if (choice == 2) {
    runPriorityScheduling(packets);
    printResults(packets, "Priority Scheduling");
}
else if (choice == 3) {
    // create copies
    vector<Packet> fifoPackets = packets;
    vector<Packet> priorityPackets = packets;

    // run both
    runFIFO(fifoPackets);
    runPriorityScheduling(priorityPackets);

    // print both
    printResults(fifoPackets, "FIFO Scheduling");
    printResults(priorityPackets, "Priority Scheduling");

    // compare performance
    double fifoWT = averageWaitingTime(fifoPackets);
    double priorityWT = averageWaitingTime(priorityPackets);

    cout << "\n--- Comparison ---\n";

    if (fifoWT < priorityWT) {
        cout << "FIFO has lower average waiting time.\n";
    }
    else if (priorityWT < fifoWT) {
        cout << "Priority Scheduling has lower average waiting time.\n";
    }
    else {
        cout << "Both have same performance.\n";
    }
}
else {
    cout << "Invalid choice." << endl;
}
    

    return 0;
}