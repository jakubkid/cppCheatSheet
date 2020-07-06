// C++ program to implement recursive QuickSort
#include <iostream>
using namespace std; 

// A utility function to swap two elements 
void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
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
void quickSortPart(int arr[], int left, int right, int idxToSort) 
{ 
    if (left < right) 
    { 
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int idxPivot = partition(arr, left, right); 

        
        // If you want to just find (idxToSort+1) smallest element
        // It is guaranteed that pivot is at correct place 
        /*if(idxPivot == idxToSort)
        {
            return; 
        }*/
        
        // Separately sort elements before 
        // partition and after partition (pivot is at correct place now)
        // Do not sort elements above idxToSort
        quickSortPart(arr, left, idxPivot - 1, idxToSort); 
        if(idxPivot < idxToSort)
        {
            quickSortPart(arr, idxPivot + 1, right, idxToSort); 
        }
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
    int arr[] = {10, 7, 6, 3, 9, 1, 5, 4, 8, 0, 20, 2}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int idxToFind = 6;
    quickSortPart(arr, 0, n - 1, idxToFind);
    cout << idxToFind << "=" << arr[idxToFind]<< endl;
    printArray(arr, n); 
    return 0; 
}
