// C++ program to implement iterative bubble sort
#include <iostream>
using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int left, int middle, int right)
{

    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    /* create temp arrays */
    int L[leftSize], R[rightSize];

    /* Copy data to temp arrays L[] and R[] */
    for (int i = 0; i < leftSize; i++)
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < rightSize; j++)
    {
        R[j] = arr[middle + 1 + j];
    }

    /* Merge the temp arrays back into arr[l..r]*/
    int idxLeft = 0;   // Initial index of left subarray
    int idxRight = 0;  // Initial index of right subarray
    int idxOut = left; // Initial index of merged subarray
    while (idxLeft < leftSize && idxRight < rightSize)
    {
        if (L[idxLeft] <= R[idxRight])
        {
            arr[idxOut] = L[idxLeft];
            idxLeft++;
        }
        else
        {
            arr[idxOut] = R[idxRight];
            idxRight++;
        }
        idxOut++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (idxLeft < leftSize)
    {
        arr[idxOut] = L[idxLeft];
        idxLeft++;
        idxOut++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (idxRight < rightSize)
    {
        arr[idxOut] = R[idxRight];
        idxRight++;
        idxOut++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int middle = left+(right-left)/2;

        // Sort first and second halves
        mergeSort(arr, left, middle);
        mergeSort(arr, middle+1, right);

        merge(arr, left, middle, right);
    }
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
