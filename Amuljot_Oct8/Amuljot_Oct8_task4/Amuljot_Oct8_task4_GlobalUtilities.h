#ifndef GLOBAL_UTILITIES_H
#define GLOBAL_UTILITIES_H

#include "Amuljot_Oct8_task4_Student.h"

// Aggregates grade distribution across multiple students
void summarizeGrades(Student *students[], int studentCount);

// Finds the highest score for a given subject across all students
const SubjectScore *findTopScorer(Student *students[], int studentCount, const std::string &subject);

// Print all Distinction scores across students
void exportAllDistinctions(Student *students[], int studentCount, const std::string &filename);

std::string gradeToString(GradeLevel level);
#endif