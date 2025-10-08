#include "Amuljot_Oct8_task3_SubjectScore.h"
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

// Method to convert GradeLevel to string
std::string gradeToString(GradeLevel g)
{
    switch (g)
    {
    case GradeLevel::Fail:
        return "Fail";
    case GradeLevel::Pass:
        return "Pass";
    case GradeLevel::Merit:
        return "Merit";
    case GradeLevel::Distinction:
        return "Distinction";
    default:
        return "Unknown";
    }
}

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