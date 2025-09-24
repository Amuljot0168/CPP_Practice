#include <iostream>
#include "Amuljot_Sept24_task2_EnhancingDate.h"

// Date constructor (should do range checking)
Date::Date(int m, int d, int y)
{
    // Validating month
    if (m >= 1 && m <= 12)
    {
        month = m; // if month ranges between (1-12)
    }
    else
    {
        throw std::invalid_argument("Invalid Month Value! Month (1-12)"); //"Print message on invalid month"
    }

    // Validate days
    if (d >= 1 && d <= daysInMonth(m, y))
    {
        day = d; // if day ranges between 1 and days in Month
    }
    else
    {
        throw std::invalid_argument("Invalid Day for the given Month and Year"); // Print message on invalid day
    }

    if (y >= 1000 && y <= 9999)
    {
        year = y; // Year must range between (1000-9999)
    }
    else
    {
        throw std::invalid_argument("Invalid Year! Year must be between (1000-9999)"); // Print message on invalid  year
    }
}

// Function to check year is a leap year or not
bool Date::isLeapYear(int yr)
{
    if ((yr % 4 == 0 && yr % 100 != 0) || (yr % 400 == 0))
    {
        return true;
    }
    return false;
}

// Function to Find daysin month based on leap year and month
int Date::daysInMonth(int m, int yr)
{
    // Check the month of February
    if (m == 2)
    {
        return isLeapYear(yr) ? 29 : 28;
    }

    // Check other months
    if (m == 4 || m == 6 || m == 9 || m == 11)
    {
        return 30;
    }
    else
    {
        return 31;
    }
}
// print Date in the format mm/dd/yyyy
void Date::print()
{
    std::cout << month << '/' << day << '/' << year;

} // end function print

void Date::nextDay()
{
    int maximumDays = daysInMonth(month, year); // First check maximum days in month of the year
    if (day < maximumDays)                      // If Days is less than maximum value then easily increment day
    {
        day++; // Increment the day
    }
    else // If days get greater than maximum days then
    {
        day = 1;        // set day=1
        if (month < 12) // Check if month is less than 12
        {
            month++; // Increment month
        }
        else // But month is greater than 12 then
        {
            month = 1; // set month=1
            year++;    // Increment the year
        }
    }
}