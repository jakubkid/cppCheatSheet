// C++ program to implement iterative bubble sort
#include <iostream>
using namespace std;

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

// A function to implement bubble sort 
void bubbleSort(int arr[], int len) 
{ 
    for (int i = 0; i < len-1; i++)
    {
        // Last i elements are already in place 
        for (int j = 0; j < len-i-1; j++)
        {
            if (arr[j] > arr[j+1]) 
            {
                swap(&arr[j], &arr[j+1]);
            }
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

// Driver code 
int main() 
{ 
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    bubbleSort(arr, n); 
    cout<<"Sorted array: \n"; 
    printArray(arr, n); 
    return 0; 
} 
