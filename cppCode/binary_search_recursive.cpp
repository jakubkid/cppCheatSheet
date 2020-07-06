// C++ program to implement recursive Binary Search
#include <iostream>
using namespace std;

// A recursive binary search function. It returns
// location of x in given array arr[left..right] is present,
// otherwise -1
// array needs to be sorted from low to high (ascending)
int binarySearch(int arr[], int left, int right, int value)
{
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == value)
        {
            return mid;
        }

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > value)
        {
            return binarySearch(arr, left, mid - 1, value);
        }

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, right, value);
    }

    // We reach here when element is not
    // present in array
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