#include "Amuljot_Sept22_task1_GradeBook.h"
#include <iostream>
#include <string>
// constructor initializes courseName with string supplied as argumen
GradeBook::GradeBook(std::string name, std::string instructorName)
{
    setCourseName(name);                     // call set function to initialize courseName
    setCourseInstructorName(instructorName); // call set function to initialize courseInstructorName
}
// end GradeBook constructor
// function to set the course name
void GradeBook::setCourseName(std::string name)
{
    courseName = name; // store the course name in the object
} // end function setCourseName

// function to get the course name
std::string GradeBook::getCourseName()
{
    return courseName; // return object's courseName
} // end function getCourseName

// Function to set Course Instructor name
void GradeBook::setCourseInstructorName(std::string instructorName)
{
    courseInstructorName = instructorName; // store the course instructor name in the object
}
// Function to get Course Instructor Name
std::string GradeBook::getCourseInstructorName()
{
    return courseInstructorName; // return object's courseInstructorName
}

// display a welcome message to the GradeBook user

void GradeBook::displayMessage()
{
    // call getCourseName to get the courseName

    std::cout << "Welcome to the grade book for \n"
              << getCourseName() << "! \n"
              << "This course is presented by: "
              << getCourseInstructorName()
              << std::endl;

} // end function displayMessage