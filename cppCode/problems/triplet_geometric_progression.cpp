// Dynamic Programming C++ implementation of LCS problem (worse case O(m*n))
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r)
{
    // Assumption is that arr is sorted in ascending order!
    // In case it is not true it needs to be sorted before running this algorithm

    unordered_map<long,long> numSecond; //holds number of pairs when key value is found
    unordered_map<long,long> numThird; //holds count of complete triplet when key value is found

    long tripNum = 0;
    for(const long& val: arr)
    {
        if (numThird.count(val))   //This value completes numThird[val] triplets
        {
            tripNum += numThird[val];
        }
        if (numSecond.count(val)) //This value is valid as 2nd part of numSecond[val] triplets
        {
            numThird[val*r] += numSecond[val];
        }
        numSecond[val*r]++;      // Possible triplet start

    }
    return tripNum;
}

int main()
{
    vector<long> arr{1, 3, 9, 9, 27, 81};
    int r = 3;
    long ans = countTriplets(arr, r);
    // 6
    cout << ans << "\n";

    return 0;
}
