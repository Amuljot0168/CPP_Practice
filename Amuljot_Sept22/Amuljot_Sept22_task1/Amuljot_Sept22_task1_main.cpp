#include <iostream>

#include "Amuljot_Sept22_task1_GradeBook.h"

int main()
{
    // Creatign objects gradebook1 and gradebook2
    GradeBook gradeBook1("CS101 Introduction to Programming in C++", "Paul Deitel"); // Initializing values with parameterised constructor
    GradeBook gradeBook2("CS102 C++ Data Structures", "Harvey Deitel");

    // Printing Initial values of course name of both books
    std::cout << "gradeBook1's initial course name is: "
              << gradeBook1.getCourseName()
              << "\ngradeBook2's initial course name is: "
              << gradeBook2.getCourseName() << std::endl;

    // Changing the value og gradebook1
    gradeBook1.setCourseName("CS101 C++ Programming");

    // Printing names of gradebooks after updating names
    std::cout << "\ngradeBook1's course name is: "
              << gradeBook1.getCourseName()
              << "\ngradeBook2's course name is: "
              << gradeBook2.getCourseName() << std::endl;

    std::cout << std::endl;

    // Using displayMessage() function to display the information of gradebooks
    gradeBook1.displayMessage();
    gradeBook2.displayMessage();

    return 0;
}