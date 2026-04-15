#ifndef PACKET_H
#define PACKET_H

using namespace std;

struct Packet {
    int id;
    int arrivalTime;
    int serviceTime;
    int priority;

    int startTime;
    int finishTime;
    int waitingTime;
    int turnaroundTime;

    Packet(int pid, int at, int st, int pr) {
        id = pid;
        arrivalTime = at;
        serviceTime = st;
        priority = pr;

        startTime = -1;
        finishTime = -1;
        waitingTime = 0;
        turnaroundTime = 0;
    }
};

#endif                                                