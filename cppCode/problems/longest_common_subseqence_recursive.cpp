// A Naive recursive implementation of LCS problem (brut force worse case O(2^n))
#include <iostream>
#include <string>
using namespace std;

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    return (a > b)? a : b;
}

/* Returns length of LCS for str1[0..str1Len-1], str2[0..str2Len-1] */
int lcs(string& str1, string& str2, size_t str1Len , size_t str2Len)
{
    if (str1Len == 0 || str2Len == 0)
    {
        return 0;
    }
    if (str1[str1Len-1] == str2[str2Len-1])
    {
        return 1 + lcs(str1, str2, str1Len-1, str2Len-1);
    }
    else
    {
        return max(lcs(str1, str2, str1Len, str2Len-1), lcs(str1, str2, str1Len-1, str2Len));
    }
}


/* Driver code */
int main()
{
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";

    int str1Len = str1.size();
    int str2Len = str2.size();

    cout<<"Length of LCS is "<< lcs( str1, str2, str1Len, str2Len );

    return 0;
}