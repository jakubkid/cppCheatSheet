// Dynamic Programming C++ implementation of LCS problem (worse case O(m*n))
#include <iostream>
#include <string>
using namespace std;

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    return (a > b)? a : b;
}

/* Returns length of LCS for str1[0..str1Len-1], str2[0..str2Len-1] */
int lcs(const string& str1, const string& str2, size_t str1Len , size_t str2Len)
{
    int lcsVal[str1Len + 1][str2Len + 1];

    /* Following steps build lcs_val[str1Len+1][str2Len+1] in
       bottom up fashion. Note that lcs_val[i][j]
       contains length of LCS of X[0..i-1]
       and Y[0..j-1] */
    for (int i = 0; i <= str1Len; i++)
    {
        for (int j = 0; j <= str2Len; j++)
        {
            if (i == 0 || j == 0)
            {
                lcsVal[i][j] = 0;
            }
            else if (str1[i - 1] == str2[j - 1])
            {
                lcsVal[i][j] = lcsVal[i - 1][j - 1] + 1;
            }

            else
            {
                lcsVal[i][j] = max(lcsVal[i - 1][j], lcsVal[i][j - 1]);
            }
        }
    }

    /* lcsVal[str1Len][str2Len] contains length of LCS
    for X[0..str1Len-1] and Y[0..str2Len-1] */
    return lcsVal[str1Len][str2Len];
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