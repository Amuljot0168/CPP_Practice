#ifndef DATEANDTIME_H
#define DATEANDTIME_H
// class Date definition
class DateAndTime
{
private:
    // Date
    int day;
    int month;
    int year;

    // Time
    int hour;
    int minute;
    int second;

    bool isLeapYear(int yr);            // Check year is leap or not
    int daysInMonth(int month, int yr); // return maximum number of days in month
public:
    DateAndTime(int month_, int year_, int day_, int hour_, int minute_, int second_); // default constructor

    void tick();           // Functio to increment seconds and also update hour,minute and day acoordingly
    void nextDay();        // Function to increment day in date also modify month and year if necessary
    void printUniversal(); // Output date and time (Universal time format)
    void printStandard();  // Output Date and Time (Standard Time Format)
};

// end class Date
#endif