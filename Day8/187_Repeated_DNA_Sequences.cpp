
#include <bits/stdc++.h>
using namespace std;

// solution

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        if (s.size() < 11)
        {
            return {};
        }

        unordered_map<string, int> frequency;
        vector<string> result;

        for (int i = 0; i <= s.size() - 10; ++i)
        {
            string sequence = s.substr(i, 10);
            frequency[sequence]++;
        }

        for (const auto &entry : frequency)
        {
            if (entry.second > 1)
            {
                result.push_back(entry.first);
            }
        }

        return result;
    }
};