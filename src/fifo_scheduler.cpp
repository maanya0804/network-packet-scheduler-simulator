#include <algorithm>
#include <vector>
#include "packet.h"

using namespace std;

void runFIFO(vector<Packet>& packets) {
    sort(packets.begin(), packets.end(), [](const Packet& a, const Packet& b) {
        return a.arrivalTime < b.arrivalTime;
    });

    int currentTime = 0;

    for (auto& p : packets) {
        if (currentTime < p.arrivalTime) {
            currentTime = p.arrivalTime;
        }

        p.startTime = currentTime;
        p.finishTime = p.startTime + p.serviceTime;
        p.waitingTime = p.startTime - p.arrivalTime;
        p.turnaroundTime = p.finishTime - p.arrivalTime;

        currentTime = p.finishTime;
    }
}