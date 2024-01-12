#include <bits/stdc++.h>
using namespace std;

// solution

class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {

        int ans = INT_MIN;
        int n = nums.size();
        int sum = 0;
        int s = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            s += nums[i] * i;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            s = s - (nums[i] * (n - 1)) + (sum - nums[i]);
            ans = max(ans, s);
        }

        return ans;
    }
};