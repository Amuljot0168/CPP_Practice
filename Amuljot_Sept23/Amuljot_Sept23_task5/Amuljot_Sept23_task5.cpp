#include <iostream>
#include <vector>
#include <cmath>

// Bucket Sort Function
void BucketSort(int arr[], int size)
{
    // creating a vector of 10 buckets which can store elements
    std::vector<std::vector<int>> bucket(10);

    // Find the maximum number in the array to determine number of passes
    int maxValue = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maxValue)
        {
            maxValue = arr[i];
        }
    }

    // Total Number of passes
    int TotalPasses = 0;
    while (maxValue > 0)
    {
        TotalPasses++;
        maxValue /= 10;
    }

    // Bucket Sort
    int position = 1; // Starting with ones place
    while (TotalPasses != 0)
    {
        // Placing values into bucket
        for (int i = 0; i < size; i++)
        {
            int idx = (arr[i] / position) % 10;
            bucket[idx].push_back(arr[i]);
        }

        // Copy the values from bucket to original array
        int index = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int num : bucket[i])
            {
                arr[index++] = num;
            }
            bucket[i].clear(); // Clear the bucket for next pass
        }

        position *= 10;
        TotalPasses--;
    }
}

int main()
{
    int number_of_values;
    std::cout << "Enter the number of values to input: ";
    std::cin >> number_of_values; // Input the size of array

    int values[number_of_values]; // Declaring the array values with size
    std::cout << "Input the values one by one: \n";
    for (int i = 0; i < number_of_values; i++)
    {
        std::cin >> values[i]; // Input each value of array
    }

    // Printing the array Before Sorting
    std::cout << "\nBefore Sorting array: \n";
    for (int i = 0; i < number_of_values; i++)
    {
        std::cout << values[i] << " ";
    }

    // Calling the BucketSort Function to sort the values array
    BucketSort(values, number_of_values);

    //  Printing the array after sorting
    std::cout << "\nAfter sorting the array: \n";
    for (int i = 0; i < number_of_values; i++)
    {
        std::cout << values[i] << " ";
    }

    return 0;
}