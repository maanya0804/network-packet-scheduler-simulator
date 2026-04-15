#ifndef METRICS_H
#define METRICS_H

#include <vector>
#include "packet.h"

using namespace std;

double averageWaitingTime(const vector<Packet>& packets) {
    double total = 0;

    for (const auto& p : packets) {
        total += p.waitingTime;
    }

    return total / packets.size();
}

double averageTurnaroundTime(const vector<Packet>& packets) {
    double total = 0;

    for (const auto& p : packets) {
        total += p.turnaroundTime;
    }

    return total / packets.size();
}

#endif