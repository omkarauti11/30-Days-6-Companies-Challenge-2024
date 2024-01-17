#include <bits/stdc++.h>
using namespace std;

// solution

/* Recursion + Memo + Bitmasking
1. Try all permutations. This will give TLE
2. Memoize for : prevIndex and elements selected in current permutation
3. For checking elements selected in current permutation, we can use bitmasking
Time : O(n * (n * 2^n))  // There will be n * 2^n dp states.
                        //For each state, we are running a n size loop to check visited elements
Space : O(n * 2^n)      // dp vector
*/
class Solution
{
public:
    int mod = 1e9 + 7;
    int find_permutations(int prevIndex, int mask, vector<vector<int>> &dp, vector<int> &nums, int count)
    {

        if (count == nums.size())
        {
            return 1;
        }

        if (dp[prevIndex][mask] != -1)
        {
            return dp[prevIndex][mask];
        }

        long long ways = 0;

        for (int i = 0; i < nums.size(); i++)
        {

            if (mask & (1 << i))
                continue;

            if (mask != 0 &&
                nums[i] % nums[prevIndex] != 0 &&
                nums[prevIndex] % nums[i] != 0)
            {
                continue;
            }

            ways = (ways + find_permutations(i, mask | (1 << i), dp, nums, count + 1)) % mod;
        }

        return dp[prevIndex][mask] = ways;
    }
    
    int specialPerm(vector<int> &nums)
    {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(1 << (n), -1));

        int mask = 0;
        int prevIndex = 0;
        int count = 0;

        return find_permutations(prevIndex, mask, dp, nums, count);
    }
};