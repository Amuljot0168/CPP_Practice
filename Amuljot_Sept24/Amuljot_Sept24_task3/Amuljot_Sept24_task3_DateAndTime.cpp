#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "Amuljot_Sept24_task3_DateAndTime.h"

// Defining and initializing values using constructor
DateAndTime::DateAndTime(int month_, int year_, int day_, int hour_, int minute_, int second_)
{
    // Validating date and time
    if (month_ < 1 || month_ > 12)
    {
        throw std::invalid_argument("Invalid month");
    }
    else
    {
        month = month_;
    }
    if (year_ < 1000 || year_ > 9999)
    {
        throw std::invalid_argument("Invalid year");
    }
    else
    {
        year = year_;
    }
    if (day_ < 1 || day_ > daysInMonth(month, year))
    {
        throw std::invalid_argument("Invalid day");
    }
    else
    {
        day = day_;
    }

    if (hour_ < 0 || hour_ > 23)
    {
        throw std::invalid_argument("Invalid hour");
    }
    else
    {
        hour = hour_;
    }
    if (minute_ < 0 || minute_ > 59)
    {
        throw std::invalid_argument("Invalid minute");
    }
    else
    {
        minute = minute_;
    }
    if (second_ < 0 || second_ > 59)
    {
        throw std::invalid_argument("Invalid second");
    }
    else
    {
        second = second_;
    }
}

// Function to check year is a leap year or not
bool DateAndTime::isLeapYear(int yr)
{
    if ((yr % 4 == 0 && yr % 100 != 0) || (yr % 400 == 0))
    {
        return true; // return true if given year is leap year
    }
    return false; // return false if given year is not a leap year
}

// Function to Find daysin month based on leap year and month
int DateAndTime::daysInMonth(int m, int yr)
{
    // Check the month of February
    if (m == 2)
    {
        return isLeapYear(yr) ? 29 : 28; // return 29 days if year is leap and 28 days if year is not leap
    }

    // Check other months
    if (m == 4 || m == 6 || m == 9 || m == 11) // These months have 30 days
    {
        return 30;
    }
    else
    {
        return 31;
    }
}

// Tick Function to increment the values of time and day
void DateAndTime::tick()
{
    second++;
    if (second == 60)
    {
        second = 0;
        minute++;
        if (minute == 60)
        {
            minute = 0;
            hour++;
            if (hour == 24)
            {
                hour = 0;
                nextDay();
            }
        }
    }
}

// Function increment the day by 1 and also update month and year accoordingly
void DateAndTime::nextDay()
{
    int maxDay = daysInMonth(month, year); // Maximum day in current month
    if (day < maxDay)                      // if day is less than maximum days then simply increment the day
    {
        day++;
    }
    else
    {

        day = 1; // Set day to 1 as it's a new  month
        if (month < 12)
        {
            month++; // Increment month if it is less than 12
        }
        else
        {
            month = 1; // if previous month = 12 than we set month value to 1
            year++;    // Increment the year
        }
    }
}

// Display Date and Time in Universal-time format (MM:DD:YYYY HH:MM::SS)
void DateAndTime::printUniversal()
{
    std::cout << std::setfill('0') << std::setw(2) << month << "/"
              << std::setw(2) << day << "/" << year << " "
              << std::setw(2) << hour << ":" << std::setw(2) << minute << ":"
              << std::setw(2) << second << std::endl;
}

// Display Date and Time in Standard-time format (MM:DD:YYYY HH:MM::SS AM or PM)
void DateAndTime::printStandard()
{
    std::cout << std::setfill('0') << std::setw(2) << month << "/"
              << std::setw(2) << day << "/" << year << " "
              << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
              << std::setw(2) << minute << ":" << std::setw(2) << second
              << (hour < 12 ? " AM" : " PM") << std::endl;
}
