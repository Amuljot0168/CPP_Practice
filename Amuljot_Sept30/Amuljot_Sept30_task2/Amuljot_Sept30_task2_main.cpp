#include <iostream>
#include "Amuljot_Sept30_task2_QuickSort.h"

int main()
{
    // Initializing the array
    int arr[] = {37, 2, 6, 4, 89, 8, 10, 12, 68, 45};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of array

    // Printing array before sorting
    std::cout << "Original array: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Calling QuickSort Function
    QuickSort(arr, 0, size - 1);

    // Printing array after sorting
    std::cout << "\nSorted array: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}