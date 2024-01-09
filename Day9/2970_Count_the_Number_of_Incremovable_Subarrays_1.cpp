#include <bits/stdc++.h>
using namespace std;

// solution

class Solution
{
public:
    bool solve(vector<int> &arr, int start, int end)
    {
        int len = arr.size();
        int prev = 0;

        for (int i = 0; i < len; i++)
        {
            if (i <= end && i >= start)
            {
                continue;
            }

            if (arr[i] <= prev)
            {
                return false;
            }

            prev = arr[i];
        }

        return true;
    }

    int incremovableSubarrayCount(vector<int> &nums)
    {
        int count = 0;
        int len = nums.size();

        for (int i = 0; i < len; i++)
        {
            for (int j = i; j < len; j++)
            {
                if (solve(nums, i, j))
                {
                    count++;
                }
            }
        }

        return count;
    }
};