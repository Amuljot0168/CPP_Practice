#include "Amuljot_Oct8_task4_SubjectScore.h"
#include "Amuljot_Oct8_task4_GlobalUtilities.h"
#include <iostream>

// Default Constructor
SubjectScore::SubjectScore()
{
    subjectName = "";
    score = 0;
    grade = GradeLevel::Fail;
}

// Parameterized Constructor
SubjectScore::SubjectScore(std::string name, int s, GradeLevel g)
    : subjectName(name), score(s), grade(g) {}

// Display the score
void SubjectScore::displayScore() const
{
    std::cout << "Subject: " << subjectName << std::endl;
    std::cout << "Score: " << score << std::endl;
    std::cout << "Grade: " << gradeToString(grade) << std::endl;
    std::cout << std::endl;
}

// Retrieve the grade
GradeLevel SubjectScore::getGrade() const
{
    return grade;
}

// Get the score
int SubjectScore::getScore() const
{
    return score;
}

// get Subject name
std::string SubjectScore::getSubjectName() const
{
    return subjectName;
}