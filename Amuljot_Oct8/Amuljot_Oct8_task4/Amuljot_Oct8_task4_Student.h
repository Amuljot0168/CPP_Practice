#ifndef STUDENT_H
#define STUDENT_H

#include "Amuljot_Oct8_task4_SubjectScore.h"

class Student
{
private:
    SubjectScore *subjects; // dynamically allocated array
    int currentCount;       // number of subjects added
    static const int MAX_SUBJECTS = 10;

public:
    Student();  // constructor
    ~Student(); // destructor

    // add Score in subjects array
    void addScore(const SubjectScore &score);

    // Calculate average Score
    double computeAverageScore() const;

    // count How many subjects are destinction
    int countDistinctions() const;

    // display all merit and distinction scores
    void printMeritAndDistinctionScores() const;

    // display all scores
    void displayAllScores() const;

    SubjectScore getSubjectAt(int index) const;
};

#endif