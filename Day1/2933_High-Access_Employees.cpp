#include <bits/stdc++.h>
using namespace std;

// Solution

class Solution
{
public:
    bool isHighAccess(vector<int> &times)
    {
        int n = times.size();

        for (int i = 2; i < n; i++)
        {
            int currTime = times[i];
            int prevPrev = times[i - 2];
            if (prevPrev + 99 >= currTime)
            {
                return true;
            }
        }
        return false;
    }

    vector<string> findHighAccessEmployees(vector<vector<string>> &at)
    {
        vector<string> ans;
        map<string, vector<int>> map;

        for (vector<string> &curr : at)
        {
            string emp = curr[0];
            string time = curr[1];

            if (map.find(emp) == map.end())
            {
                map[emp] = vector<int>();
            }
            int t = stoi(time);
            map[emp].push_back(t);
        }

        for (auto entry : map)
        {
            vector<int> times = entry.second;
            sort(times.begin(), times.end());

            if (isHighAccess(times))
            {
                ans.push_back(entry.first);
            }
        }
        return ans;
    }
};