#include <bits/stdc++.h>
using namespace std;

// Solution

class Solution
{
public:
    struct Pair
    {
        string s;
        int index;
        Pair(string s, int index) : s(s), index(index) {}
    };

    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {

        unordered_map<int, vector<Pair>> map;

        for (int i = 0; i < nums.size(); i++)
        {

            string str = nums[i];
            int n = str.length();
            int l = n;

            for (int j = 0; j < n; j++)
            {

                map[l].emplace_back(str.substr(j), i);
                l--;
            }
        }

        vector<int> ans(queries.size());

        int idx = 0;

        for (const auto &query : queries)
        {

            int kthElement = query[0];
            int key = query[1];

            auto &list = map[key];

            sort(list.begin(), list.end(), [](const Pair &p1, const Pair &p2)
                {
                    if (p1.s == p2.s){
                        return p1.index < p2.index;
                    }
                    return p1.s < p2.s;
                }
            );

            ans[idx++] = list[kthElement - 1].index;
        }

        return ans;
    }
};