#include <iostream>
#include "Amuljot_Sept23_task1_DuplicateElemination.h"

// Function to check if input number is between range of 10 and 100
bool isValid(int num)
{
    return num >= MIN_VALUE && num <= MAX_VALUE;
}

// Function to check input number is duplicate or not
bool isDuplicate(int arr[], int size, int num)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
            return true;
    }
    return false;
}

// Function to input only unique values
int readUniqueValues(int arr[])
{
    int count = 0; // cariable count for storing unique values
    for (int i = 0; i < MAX_INPUTS; ++i)
    {
        int num;
        std::cout << "Enter number " << (i + 1) << ". (between 10 and 100): ";
        std::cin >> num;

        // if input number is not valid then make i-- to re-take the input
        if (!isValid(num))
        {
            std::cout << "Invalid input. Please enter a number between 10 and 100.\n";
            --i;
            continue;
        }

        // Check if input number is a unique value
        if (!isDuplicate(arr, count, num))
        {
            arr[count++] = num;
        }
    }
    return count;
}

// Function to display all unique values entered
void displayUniqueValues(int arr[], int size)
{
    std::cout << "There are " << size << " Unique values: \n";

    // Loop to traverse array
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
