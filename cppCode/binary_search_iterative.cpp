// C++ program to implement iterative Binary Search
#include <iostream>
using namespace std;

// A iterative binary search function. It returns
// location of x in given array arr[left..right] is present,
// otherwise -1
// array needs to be sorted from low to high (ascending)
int binarySearch(int arr[], int left, int right, int value)
{
    while (left <= right) { 
        int mid = left + (right - l) / 2; 
  
        // Check if x is present at mid 
        if (arr[mid] == value) 
            return mid; 
  
        // If x greater, ignore left half 
        if (arr[mid] < value) 
            left = mid + 1; 
  
        // If x is smaller, ignore right half 
        else
            right = mid - 1; 
    } 
  
    // if we reach here, then element was 
    // not present 
    return -1; 
}

int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                : cout << "Element is present at index " << result;
    return 0;
}