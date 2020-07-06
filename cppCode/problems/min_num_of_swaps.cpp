// Dynamic Programming C++ implementation of LCS problem (worse case O(m*n))
#include <iostream>
#include <vector>

using namespace std;


int minimumSwaps(vector<int> arr)
{
    size_t tabLen = arr.size();
    int swapNum = 0;
    for(size_t pos=0; pos < tabLen-1; pos++)
    {
        //value should be pos+1
        if(arr[pos] > pos+1)
        {
            swapNum++;
        }
        else if(arr[pos] < pos+1)
        {
            //current element was already swapped find out its current value
            int curVal = arr[pos];
            while(arr[curVal-1] < pos+1)
            {
                curVal = arr[curVal-1];
            }
            if(arr[curVal-1] != (pos+1))
            {
                swapNum++;
            }
        }
    }
    return swapNum;
}

int main()
{
    vector<int> arr{1, 3, 5, 2, 4, 6, 7};

    int res = minimumSwaps(arr);
    //3
    cout << res << "\n";

    return 0;
}