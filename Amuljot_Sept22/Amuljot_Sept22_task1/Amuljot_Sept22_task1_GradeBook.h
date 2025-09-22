// Header Gaurds
#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <string>

// GradeBook class definition

// Declaring the GradeBook Class
class GradeBook

{

private:
    std::string courseName;           // course name for this GradeBook
    std::string courseInstructorName; // course instructor name for this GradeBook

public:
    GradeBook(std::string, std::string);       // constructor that initializes courseName
    void setCourseName(std::string);           // function that sets the course name
    std::string getCourseName();               // function that gets the course name
    void setCourseInstructorName(std::string); // function that sets the course instructor name
    std::string getCourseInstructorName();     // function that gets the course instructor name
    void displayMessage();                     // function that displays a welcome message
}; // end class GradeBook

#endif