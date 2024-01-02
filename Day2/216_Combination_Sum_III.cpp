#include <bits/stdc++.h>
using namespace std;

// solution

class Solution
{
public:
    vector<vector<int>> result;
    void solve(vector<int> &nums, vector<int> &temp, int idx, int k, int target)
    {
        if (target == 0 && temp.size() == k)
        {
            result.push_back(temp);
            return;
        }

        if (idx >= nums.size() || target < 0)
        {
            return;
        }

        for (int i = idx; i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
            solve(nums, temp, i + 1, k, target - nums[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> temp;

        solve(nums, temp, 0, k, n);

        return result;
    }
};