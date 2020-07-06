// C++ program to implement shit array left in place
#include <iostream>
#include <vector>
using namespace std;

vector<string> split_string(string);

int greatestCommonDivisor(int a, int b) 
{
  while(b != 0)
  {
     int div = b;
     b = a % div;
     a = div;
  }
  return a;
} 
void swap(int* a, int* b)
{
    int tmp = *b;
    *b=*a;
    *a=tmp;
    /* cannot be the same :o
    a = a^b;
    b = a^b;
    a = a^b;
    */
}
// Complete the rotLeft function below.
vector<int> rotLeft(vector<int> a, int d) 
{
    int len = a.size();
    int numSets = greatestCommonDivisor(len, d);
    for(int startIdx =0; startIdx < numSets; startIdx++)
    {
        int swapIdx = startIdx + len - d;
        while(swapIdx != startIdx)
        {
            swap(&a[startIdx], &a[swapIdx]);
            //cout << "start "<< startIdx << " swap " <<swapIdx <<endl;
            swapIdx = (swapIdx  + len - d) % len;
        }
    }

    return a;
}

int main()
{
    vector<int> vectorToshift = {41, 73, 89, 7, 10, 1, 59, 58, 84, 77, 77, 97, 58, 1, 86, 58, 26, 10, 86, 51};
    int numToShift = 10;
    vector<int> result = rotLeft(vectorToshift, numToShift);
    
    cout << "Shift by " << numToShift << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << " ";
        }
    }

    cout << "\n";

    return 0;
}