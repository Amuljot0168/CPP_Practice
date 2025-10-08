#include "Amuljot_Oct8_task3_Student.h"
#include <iostream>

int main()
{
    // Creating Student Object
    Student student1;

    // Adding sample scores of student
    student1.addScore(SubjectScore("Math", 92, GradeLevel::Distinction));
    student1.addScore(SubjectScore("Physics", 78, GradeLevel::Merit));
    student1.addScore(SubjectScore("Chemistry", 65, GradeLevel::Pass));
    student1.addScore(SubjectScore("History", 45, GradeLevel::Fail));
    student1.addScore(SubjectScore("English", 88, GradeLevel::Distinction));

    // Displaying all scores
    std::cout << "Scores of student: \n";
    student1.displayAllScores();

    // Average score of student
    std::cout << "\n Average score: " << student1.computeAverageScore() << std::endl;

    // Display number of subjects are distinction
    std::cout << "Number of Distinction subjects: " << student1.countDistinctions() << std::endl;

    // Printing top scores
    std::cout << "\nTop Scores of student: \n";
    student1.printMeritAndDistinctionScores();
    return 0;
}