#include <iostream>
#include <iomanip>
#include "Amuljot_Sept24_task4_ErrorIndicators.h"

Time::Time(int hr, int min, int sc)
{
    setTime(hr, min, sc);
}

// Set new Time value
bool Time::setTime(int h, int m, int s)
{
    return setHour(h) && setMinute(m) && setSecond(s); // set private field second
}

// set hour value
bool Time::setHour(int h)
{
    // validate hours
    if (h >= 0 && h < 24)
    {
        hour = h;
        return true;
    }
    return false;
}

// set minute value
bool Time::setMinute(int m)
{
    // validate minutes
    if (m >= 0 && m < 60)
    {
        minute = m;
        return true;
    }
    return false;
}

// set second value
bool Time::setSecond(int s)
{
    // Validate seconds
    if (s >= 0 && s < 60)
    {
        second = s;
        return true;
    }
    return false;
}

// get functions
int Time::getHour()
{
    return hour; // return hour value
}
int Time::getMinute()
{
    return minute; // return minute value
}
int Time::getSecond()
{
    return second; // return second value
}

// Print Time in Universal-time format (HH:MM:SS)
void Time::printUniversal()
{
    std::cout << std::setfill('0') << std::setw(2) << getHour() << ":" << std::setw(2) << getMinute() << ":" << std::setw(2) << getSecond() << std::endl;
}

// Print Time in Standard Format (HH:MM:SS AM or PM)
void Time::printStandard()
{
    std::cout << ((getHour() == 0 || getHour() == 12) ? 12 : (getHour() % 12)) << ":" << std::setfill('0') << std::setw(2) << getMinute() << ":" << std::setw(2) << getSecond() << (hour < 12 ? " AM" : " PM") << std::endl;
}

// Tick Member Function
void Time::tick()
{
    int sec = (getSecond() + 1);
    if (sec == 60)
    {
        sec = 0;
        int min = (getMinute() + 1);

        if (min == 60)
        {
            min = 0;
            int hr = (getHour() + 1);
            if (hr == 24)
            {
                hr = 0;
            }
            setHour(hr);
        }
        setMinute(min);
    }
    setSecond(sec);
}
