// C++ program to implement iterative insertion sort
#include <iostream>
using namespace std; 
  
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int len)  
{    
    for (int i = 1; i < len; i++) 
    {  
        int element = arr[i];  

  
        /* Move elements of arr[0..i-1], that are  
        greater than element, to one position ahead  
        of their current position */
        for(int j = (i - 1); j >= 0 ; j--)
        {       
            if(arr[j] > element) 
            {
                // The element is not at the right place 
                arr[j + 1] = arr[j];
                // when we reach 0 it means we have found the smallest one
                if(j == 0)
                {
                    arr[j] = element;
                }
            }
            else
            {
                // Right location has been found
                arr[j+1] = element;
                break;
            }               
        } 
        /* //More compact
        int j = i - 1;  
  
        while (j >= 0 && arr[j] > element) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = element;
        */
    }  
}  
  
// A utility function to print an array of size n  
void printArray(int arr[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl; 
} 
  
/* Driver code */
int main()  
{  
    int arr[] = { 12, 11, 13, 5, 6 };  
    int n = sizeof(arr) / sizeof(arr[0]);  
  
    insertionSort(arr, n);  
    printArray(arr, n);  
  
    return 0;  
}  