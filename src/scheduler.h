#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include "packet.h"

void runFIFO(std::vector<Packet>& packets);
void runPriorityScheduling(std::vector<Packet>& packets);

#endif