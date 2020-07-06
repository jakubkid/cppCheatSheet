// C++ program to implement recursive QuickSort
#include <iostream>
using namespace std; 

// A utility function to swap two elements 
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int partition (int arr[], int left, int right) 
{ 
    int pivot = arr[right]; // pivot (last element)
    int idxSmaller = left; // Index of smaller element (first element) 

    for (int i = left; i <= right - 1; i++) 
    {
        // If current element is smaller than the pivot 
        if (arr[i] < pivot) 
        { 
            swap(&arr[idxSmaller], &arr[i]); 
            idxSmaller++; // increment index of smaller element 
        } 
    } 
    swap(&arr[idxSmaller], &arr[right]); // Place pivot to correct position
    return idxSmaller; 
} 

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int left, int right) 
{ 
    if (left < right) 
    { 
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int idxPivot = partition(arr, left, right); 

        // Separately sort elements before 
        // partition and after partition (pivot is at correct place now)
        quickSort(arr, left, idxPivot - 1); 
        quickSort(arr, idxPivot + 1, right); 
    } 
} 

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

// Driver Code 
int main() 
{ 
    int arr[] = {10, 7, 8, 9, 1, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    quickSort(arr, 0, n - 1); 
    cout << "Sorted array: \n"; 
    printArray(arr, n); 
    return 0; 
} 

// This code is contributed by rathbhupendra 
