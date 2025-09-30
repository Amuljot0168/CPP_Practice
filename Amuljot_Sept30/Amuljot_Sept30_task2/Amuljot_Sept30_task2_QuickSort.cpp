#include <iostream>
#include "Amuljot_Sept30_task2_QuickSort.h"

// Function Partition the array into sub arrays and return pivotIndex
int partition(int arr[], int left, int right)
{
    int pivotIndex = left;
    int pivot = arr[pivotIndex];
    int leftIndex = left + 1;
    int rightIndex = right;

    while (leftIndex <= rightIndex)
    {
        while (leftIndex <= right && arr[leftIndex] < pivot)
        {
            leftIndex++;
        }
        while (rightIndex >= left && arr[rightIndex] > pivot)
        {
            rightIndex--;
        }

        if (leftIndex < rightIndex)
        {
            swap(arr, leftIndex, rightIndex);
            leftIndex++;
            rightIndex--;
        }
        else
        {
            break;
        }
    }
    swap(arr, pivotIndex, rightIndex);
    pivotIndex = rightIndex; // Updating pivotIndex
    return pivotIndex;       // returning pivot element index
}

// Swap function to swap elements of array
void swap(int arr[], int index1, int index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

// Quick Sort Function
void QuickSort(int arr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int pivotIndex = partition(arr, left, right);
    std::cout << "Pivot placed at index " << pivotIndex << ": ";
    for (int i = left; i <= right; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    QuickSort(arr, left, pivotIndex - 1);  // Sort left subarray
    QuickSort(arr, pivotIndex + 1, right); // Sort right subarray
}
