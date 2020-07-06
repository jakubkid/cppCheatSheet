// A max sub set sum implementation (O(n))
#include <iostream>
#include <string>
using namespace std;

// Complete the abbreviation function below.
string abbreviation(string a, string b)
{
    bool isValid[a.size() + 1][b.size() + 1];
    isValid[0][0] = true; // if both a and b are empty they are abbreviation
    // empty a and any non empty b is not an abbreviation so the rest of row 0 is false
    for(size_t i = 1; i <= b.size(); i++)
    {
        isValid[0][i] = false;
    }
    // Only lower case characters can be removed
    bool containsUppercase = false;
    for (size_t k = 1; k <= a.length(); k++)
    {
        int i = k - 1;
        // if the pointer at string a is uppercase
        if (isupper(a[i]) || containsUppercase)
        {
            containsUppercase = true;
            isValid[k][0] = false;
        }
        else
        {
            isValid[k][0] = true;
        }
    }
    // Table initialization done

    // tabulation from start of string
    for (size_t k = 1; k <= a.length(); k++)
    {
        for (size_t l = 1; l <= b.length(); l++)
        {
            int aIdx = k - 1;
            int bIdx = l - 1;
            // when the characters are equal, set = previous string validity.
            if (a[aIdx] == b[bIdx])
            {
                isValid[k][l] = isValid[k - 1][l - 1];
                continue;
            }
            // elif uppercase a == b, set = prev character a validity. or just eat a.
            else if (toupper(a[aIdx]) ==  b[bIdx])
            {
                isValid[k][l] = isValid[k - 1][l - 1] || isValid[k - 1][l];
                continue;
            }
            // elif a is uppercase and no more b, or uppercase a is not b, then false
            else if (isupper(a[aIdx]))
            {
                isValid[k][l] = false;
                continue;
            }
            //else just eat a
            else
            {
                isValid[k][l] = isValid[k-1][l];
                continue;
            }
        }
    }
    return isValid[a.length()][b.length()]? "YES" : "NO";

}

int main()
{
    string str1 = "daBcd";
    string str2 = "ABC";

    string result = abbreviation(str1, str2);
    //yes
    cout << result << "\n";

    return 0;
}