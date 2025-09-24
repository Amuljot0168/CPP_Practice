#ifndef ERROR_INDICATORS_H
#define ERROR_INDICATORS_H

class Time
{
private:
    int hour;   // 0-23 (24 houres clock format)
    int minute; // 0-59
    int second; // 0-59

public:
    // Default Constructor
    Time(int = 0, int = 0, int = 0);

    // set functions
    bool setTime(int = 0, int = 0, int = 0); // set hour,minute,second
    bool setHour(int);                       // set hour
    bool setMinute(int);                     // set minutes
    bool setSecond(int);                     // set seconds

    // Get Functions
    int getHour();   // return hour
    int getMinute(); // return minute
    int getSecond(); // return seconds

    // Member Function
    void printUniversal(); // output time in universal-time format
    void printStandard();  // output time in standard-time format
    void tick();
};
#endif