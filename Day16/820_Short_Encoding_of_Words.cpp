
#include <bits/stdc++.h>
using namespace std;

// solution

class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {

        unordered_set<string> wordSet(words.begin(), words.end());

        for (const string &s : words)
        {
            for (int i = 1; i < s.length(); ++i)
            {
                wordSet.erase(s.substr(i));
            }
        }

        int length = 0;

        for (const string &s : wordSet)
        {
            length += s.length() + 1;
        }

        return length;
    }
};