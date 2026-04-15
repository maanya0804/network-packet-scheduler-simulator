# Network Packet Scheduler Simulator (C++)

A terminal-based C++ simulator that models packet scheduling in a network system using FIFO and Priority Scheduling algorithms.

## Features
- Simulates packet arrival, queuing, and service execution
- Implements FIFO (First-In-First-Out) scheduling
- Implements Non-Preemptive Priority Scheduling
- Calculates performance metrics:
  - Average Waiting Time
  - Average Turnaround Time
- Allows user input for dynamic packet creation
- Compares scheduling algorithms based on performance
- Displays execution using Gantt Chart visualization

## Concepts Used
- C++ (STL: vector, sort)
- Scheduling Algorithms
- Simulation Logic
- Performance Analysis

## Project Structure
```text
src/
├── main.cpp
├── packet.h
├── scheduler.h
├── fifo_scheduler.cpp
├── priority_scheduler.cpp
└── metrics.h