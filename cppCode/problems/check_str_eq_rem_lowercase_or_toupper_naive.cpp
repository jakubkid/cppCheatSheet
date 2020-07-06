// A max sub set sum implementation (O(n))
#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Complete the abbreviation function below.
string abbreviation(string a, string b)
{
    //cout << "start" << endl;
    if(a.size() >= b.size())
    {
        queue<int> upperAIdx;
        queue<int> upperBIdx;
        upperAIdx.push(0);
        upperBIdx.push(0);
        while(upperAIdx.size()>0)
        {
            //cout << "again" << endl;
            int bIdx = upperBIdx.front();
            int i= upperAIdx.front();
            upperBIdx.pop();
            upperAIdx.pop();
            for(; i < a.size(); i++)
            {
                if((a.size()+i-bIdx) < b.size())
                {
                    break;// no need to check next
                }
                if(a[i] == b[bIdx] || toupper(a[i]) == b[bIdx])
                {
                    if(toupper(a[i]) == b[bIdx])
                    {
                        upperAIdx.push(i+1);// next time don't uppercase this
                        upperBIdx.push(bIdx);
                    }
                    //cout << "a["<< i<< "]: " << a[i] << " b["<< bIdx << "]: " << b[bIdx] << endl;
                    bIdx++;
                    if(bIdx >=b.size())
                    {
                        bool upperFound = false;
                        // check if all remaining charactes are lower case
                        for(int lowIdx=i+1; lowIdx < a.size(); lowIdx++)
                        {
                            if(isupper(a[lowIdx]))
                            {
                                upperFound = true;
                            }
                        }
                        if(upperFound)
                        {
                            break;
                        }
                        return "YES";
                    }
                }
                else if(isupper(a[i]))
                {
                    // cannot remove uppercase caractes
                    break;
                }
            }
        }
    }
    return "NO";

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