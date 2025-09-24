#ifndef ENHANCING_CLASS_H
#define ENHANCING_CLASS_H

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
    void setTime(int = 0, int = 0, int = 0); // set hour,minute,second
    void setHour(int);                       // set hour
    void setMinute(int);                     // set minutes
    void setSecond(int);                     // set seconds

    // Get Functions
    int getHour();   // return hour
    int getMinute(); // return minute
    int getSecond(); // return seconds

    // Member Function
    void printUniversal(); // output time in universal-time format
    void printStandard();  // output time in standard-time format
    void tick();           // Increment the seconds and update hours,minutes and seconds
};
#endif