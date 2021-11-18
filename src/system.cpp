#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "process.h"
#include "processor.h"
#include "system.h"
#include "form.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;
using std::sort;

Processor& System::Cpu() { 
    cpu_ = Processor(LinuxParser::CpuUtilization());
    return cpu_; 
}

vector<Process>& System::Processes() { 
    processes_ = {};
    vector<int> pids = LinuxParser::Pids();
    for(long unsigned int i = 0; i<pids.size(); i++){
        Process process = Process(pids[i]);
        processes_.push_back(process);
    }
    sort(processes_.begin(), processes_.end());
    return processes_; 
}

std::string System::Kernel() { 
    return  LinuxParser::Kernel();
}

std::string System::OperatingSystem() { 
    return LinuxParser::OperatingSystem();
}

float System::MemoryUtilization() { 
    return LinuxParser::MemoryUtilization();
}

long int System::UpTime() { 
    return LinuxParser::UpTime();
}

int System::TotalProcesses() { 
    return LinuxParser::TotalProcesses();
}

int System::RunningProcesses() { 
    return LinuxParser::RunningProcesses();
}
