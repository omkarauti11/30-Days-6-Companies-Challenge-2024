#include <bits/stdc++.h>
using namespace std;

// solution


class Solution
{
public:
    bool isSubsequence(const string &S, const string &D)
    {

        int i = 0, j = 0;

        if (D.length() > S.length())
        {
            return false;
        }

        while (i < S.length() && j < D.length())
        {

            if (S[i] == D[j])
            {
                j++;
            }

            i++;
        }

        return j == D.length();
    }

    string findLongestWord(string s, vector<string> &d)
    {

        string result = "";

        sort(d.begin(), d.end(), [](const string &a, const string &b){ return a.length() == b.length() ? a < b : a.length() > b.length(); });

        for (const string &str : d)
        {
            if (isSubsequence(s, str))
            {
                result = str;
                break;
            }
        }

        return result;
    }
};