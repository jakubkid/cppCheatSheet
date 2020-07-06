// A max sub set sum implementation (O(n))
#include <iostream>
#include <vector>
using namespace std;

// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> arr) 
{
    if (arr.size() == 1)
    {
        return arr[0];
    }

    int maxPrevPrev = arr[0];
    int maxPrev = max(arr[0], arr[1]);
    for(int i=2; i < arr.size(); i++)
    {
        int max = arr[i];
        if(arr[i]+maxPrevPrev > max)
        {
            max = arr[i]+maxPrevPrev;
        }
        if(maxPrev > max)
        {
            max = maxPrev;
        }
        maxPrevPrev = maxPrev;
        maxPrev = max;
    }
    return max(maxPrev, maxPrevPrev); 
}

int main()
{
    vector<int> array{3, 5, -7, 8, 10};
	// max sum 15 [5,10]

    int res = maxSubsetSum(array);

    cout << res << "\n";

    return 0;
}