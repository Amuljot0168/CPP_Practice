#ifndef DUPLICATION_ELEMINATION_H
#define DUPLICATION_ELEMINATION_H

// Constant variables
const int MAX_INPUTS = 20;
const int MIN_VALUE = 10;
const int MAX_VALUE = 100;

// Function declarations
bool isValid(int num);
bool isDuplicate(int arr[], int size, int num);
int readUniqueValues(int arr[]);
void displayUniqueValues(int arr[], int size);

#endif