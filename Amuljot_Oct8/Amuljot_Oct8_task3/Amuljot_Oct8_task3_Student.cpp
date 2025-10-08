#include "Amuljot_Oct8_task3_Student.h"
#include <iostream>

// Constructor
Student::Student()
{
    subjects = new SubjectScore[MAX_SUBJECTS];
    currentCount = 0;
}

// Destructor
Student::~Student()
{
    delete[] subjects;
}

// Add a score in subjectsScore array
void Student::addScore(const SubjectScore &score)
{
    if (currentCount < MAX_SUBJECTS)
    {
        subjects[currentCount++] = score; //
    }
    else
    {
        std::cout << "No space  to store the scores\n";
    }
}

// Compute average score
double Student::computeAverageScore() const
{
    if (currentCount == 0)
        return 0.0;

    int totalSum = 0;
    for (int i = 0; i < currentCount; ++i)
    {
        totalSum += subjects[i].getScore(); // Calculating sum of scores of students
    }

    double averageScore = static_cast<double>(totalSum) / currentCount; // Average Score
    return averageScore;                                                // return averageScore
}

// Count students whose grade level is Distinctions
int Student::countDistinctions() const
{
    int count = 0;
    for (int i = 0; i < currentCount; ++i)
    {
        if (subjects[i].getGrade() == GradeLevel::Distinction)
        {
            count++;
        }
    }
    return count;
}

// Print Merit and Distinction scores
void Student::printMeritAndDistinctionScores() const
{
    for (int i = 0; i < currentCount; ++i)
    {
        GradeLevel grade = subjects[i].getGrade();
        if (grade == GradeLevel::Merit || grade == GradeLevel::Distinction)
        {
            subjects[i].displayScore();
            std::cout << std::endl;
        }
    }
}

// Print all scores of student

void Student::displayAllScores() const
{
    for (int i = 0; i < currentCount; i++)
    {
        subjects[i].displayScore();
    }
}