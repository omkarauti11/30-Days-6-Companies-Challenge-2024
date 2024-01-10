
#include <bits/stdc++.h>
using namespace std;

// solution

class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<int> res(n);

        int i = 1;
        int j = n - 1;

        while (i < n)
        {
            res[i] = nums[j];
            i += 2;
            j--;
        }

        i = 0;

        while (i < n)
        {
            res[i] = nums[j];
            i += 2;
            j--;
        }

        for (i = 0; i < n; i++)
        {
            nums[i] = res[i];
        }
    }
};