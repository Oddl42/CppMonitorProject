#include "processor.h"
#include <vector>
#include <string>
#include <iostream>
#include "linux_parser.h"

using std::stol;

// Return the aggregate CPU utilization
float Processor::Utilization() { 
    long user = stol(cpuUsage_[0]);
    long nice = stol(cpuUsage_[1]);
    long system = stol(cpuUsage_[2]);
    long idle = stol(cpuUsage_[3]);
    long iowait = stol(cpuUsage_[4]);
    long irq = stol(cpuUsage_[5]);
    long softirq = stol(cpuUsage_[6]);
    long steal = stol(cpuUsage_[7]);
    long guest = stol(cpuUsage_[8]);
    long guest_nice = stol(cpuUsage_[9]);

    long idleTime = idle + iowait;
    long totalTime = user + nice + system + idle + iowait + irq + softirq + steal + guest + guest_nice;

    if (totalTime != 0){
        return (float) (totalTime - idleTime)/totalTime;
    }
    return 0.0; 
}
