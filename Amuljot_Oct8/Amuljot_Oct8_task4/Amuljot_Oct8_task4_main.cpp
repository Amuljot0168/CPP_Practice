#include "Amuljot_Oct8_task4_Student.h"
#include "Amuljot_Oct8_task4_GlobalUtilities.h"
#include <iostream>

int main()
{
    // Create an array of Student* with 3 students
    Student *students[3];
    students[0] = new Student();
    students[1] = new Student();
    students[2] = new Student();

    // Populate each with sample scores
    students[0]->addScore(SubjectScore("Math", 92, GradeLevel::Distinction));
    students[0]->addScore(SubjectScore("Physics", 78, GradeLevel::Merit));
    students[0]->addScore(SubjectScore("Chemistry", 65, GradeLevel::Pass));

    students[1]->addScore(SubjectScore("History", 45, GradeLevel::Fail));
    students[1]->addScore(SubjectScore("English", 88, GradeLevel::Distinction));
    students[1]->addScore(SubjectScore("Math", 85, GradeLevel::Merit));

    students[2]->addScore(SubjectScore("English", 90, GradeLevel::Distinction));
    students[2]->addScore(SubjectScore("Physics", 55, GradeLevel::Pass));
    students[2]->addScore(SubjectScore("Chemistry", 40, GradeLevel::Fail));

    // Call summarizeGrades() to display grade distribution
    summarizeGrades(students, 3);

    // Call findTopScorer() for "Math" and display result
    const SubjectScore *topMath = findTopScorer(students, 3, "Math");
    if (topMath)
    {
        std::cout << "\nTop Scorer in Math:\n";
        topMath->displayScore();
        delete topMath; // clean up dynamically allocated copy
    }
    else
    {
        std::cout << "\nNo Math scores found.\n";
    }

    // Call exportAllDistinctions()
    exportAllDistinctions(students, 3, "export.txt");

    // Clean up memory
    for (int i = 0; i < 3; ++i)
    {
        delete students[i];
    }

    return 0;
}