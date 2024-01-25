#include <bits/stdc++.h>
using namespace std;

// solution

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {

        int n = nums.size();

        map<int, int> mp;

        int l = 0;
        int ans = 0;

        for (int r = 0; r < nums.size(); ++r)
        {

            if (mp.find(nums[r]) != mp.end())
            {

                mp[nums[r]] = mp[nums[r]] + 1;
            }
            else
            {
                mp[nums[r]] = 1;
            }

            while (mp[nums[r]] > k)
            {

                mp[nums[l]] -= 1;
                l += 1;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};