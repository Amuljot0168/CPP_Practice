#ifndef SUBJECTSCORE_H
#define SUBJECTSCORE_H

#include <string>
#include "Amuljot_Oct8_task4_GradeLevel.h"

class SubjectScore
{
private:
    std::string subjectName;
    int score;
    GradeLevel grade;

public:
    SubjectScore(); // default Constructor
    SubjectScore(std::string, int, GradeLevel);

    // Display the score
    void displayScore() const;

    // retrieve the grade
    GradeLevel getGrade() const;

    // retrieve the score
    int getScore() const;

    // retrieve the subject name
    std::string getSubjectName() const;
};
#endif