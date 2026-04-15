#include <vector>
#include "packet.h"

using namespace std;

void runPriorityScheduling(vector<Packet>& packets) {
    int n = packets.size();
    vector<bool> completed(n, false);

    int currentTime = 0;
    int completedCount = 0;

    while (completedCount < n) {
        int selectedIndex = -1;

        for (int i = 0; i < n; i++) {
            if (!completed[i] && packets[i].arrivalTime <= currentTime) {
                if (selectedIndex == -1 || packets[i].priority < packets[selectedIndex].priority) {
                    selectedIndex = i;
                }
            }
        }

        if (selectedIndex == -1) {
            currentTime++;
            continue;
        }

        packets[selectedIndex].startTime = currentTime;
        packets[selectedIndex].finishTime = currentTime + packets[selectedIndex].serviceTime;
        packets[selectedIndex].waitingTime = packets[selectedIndex].startTime - packets[selectedIndex].arrivalTime;
        packets[selectedIndex].turnaroundTime = packets[selectedIndex].finishTime - packets[selectedIndex].arrivalTime;

        currentTime = packets[selectedIndex].finishTime;
        completed[selectedIndex] = true;
        completedCount++;
    }
}