#ifndef QUICKSORT_H
#define QUICKSORT_H

// Declaring functions for Quick Sort
void QuickSort(int arr[], int left, int right);

// Function to return pivotIndex after Partitioning
int partition(int arr[], int left, int right);

// Swap function to swap elements of array
void swap(int arr[], int index1, int index2);

#endif