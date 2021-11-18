#include <string>

#include "format.h"

using std::string;
using std::to_string;

// Done: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
string Format::ElapsedTime(long times) {
    unsigned long hours = times/3600;
    unsigned short minutes = (times%3600)/60;
    unsigned short seconds = times - ( (hours*3600) + (minutes*60) );
    string hourOut, minOut, secOut;
    if (hours<10)
        hourOut = "0" + to_string(hours);
    else
        hourOut = to_string(hours);

    if (minutes<10)
        minOut = "0" + to_string(minutes);
    else
        minOut = to_string(minutes);

    if (seconds<10)
        secOut = "0" + to_string(seconds);
    else
        secOut = to_string(seconds);

    return hourOut + ":" + minOut + ":" + secOut; 
}    
