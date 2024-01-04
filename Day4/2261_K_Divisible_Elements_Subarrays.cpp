
#include <bits/stdc++.h>
using namespace std;

// solution

class Solution
{
public:
    int countDistinct(vector<int> &nums, int k, int p)
    {

        int n = nums.size();

        set<vector<int>> all;

        for (int j = 0; j < n; j++)
        {
            vector<int> curr;
            int divisible_by_p = 0;

            for (int i = j; i >= 0; i--)
            {

                curr.push_back(nums[i]);

                if (nums[i] % p == 0)
                {
                    divisible_by_p++;
                }

                if (divisible_by_p <= k)
                {
                    all.insert(curr);
                }
                else
                {
                    break;
                }
            }
        }

        return all.size();
    }
};