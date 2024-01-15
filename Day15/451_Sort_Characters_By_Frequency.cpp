
#include <bits/stdc++.h>
using namespace std;

// solution

class Solution
{
public:
    string frequencySort(string s)
    {

        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> pq;
        string ans = "";

        for (char ch : s)
        {
            mp[ch]++;
        }

        for (auto it : mp)
        {
            pq.push({it.second, it.first});
        }

        while (!pq.empty())
        {
            auto temp = pq.top();
            int freq = temp.first;
            char ch = temp.second;

            ans += string(freq, ch);

            pq.pop();
        }

        return ans;
    }
};