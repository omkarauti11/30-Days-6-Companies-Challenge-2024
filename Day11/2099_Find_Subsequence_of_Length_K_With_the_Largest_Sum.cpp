
#include <bits/stdc++.h>
using namespace std;

// solution

class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {

        int n = nums.size();

        vector<pair<int, int>> vp;

        for (int i = 0; i < n; i++)
        {
            vp.push_back(make_pair(nums[i], i));
        }

        sort(vp.begin(), vp.end());

        vector<int> ansIdx;

        for (int i = n - 1; i >= 0 && k--; i--)
        {
            ansIdx.push_back(vp[i].second);
        }

        sort(ansIdx.begin(), ansIdx.end());

        vector<int> fans;

        for (auto val : ansIdx)
        {
            fans.push_back(nums[val]);
        }

        return fans;
    }
};