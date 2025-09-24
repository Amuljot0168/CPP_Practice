#ifndef ENHANCING_DATE_H
#define ENHANCING_DATE_H

// class Date definition
class Date
{
    // Private Data Members
private:
    int month;
    int day;
    int year;

public:
    Date(int = 1, int = 1, int = 2000); // default constructor

    void print();   // Output the date
    void nextDay(); // Function to increment day in date also modify month and year if necessary

    bool isLeapYear(int yr);            // Check year is leap or not
    int daysInMonth(int month, int yr); // return maximum number of days in month

}; // end class Date
#endif