
#include <bits/stdc++.h>
using namespace std;

// solution

class Solution
{
public:
    long long dp[4001][1001];

    long long solve(int curr, int t, int k)
    {

        if (k == 0 && curr == t)
        {
            return 1;
        }

        if (k == 0)
        {
            return 0;
        }

        if (dp[curr + 1000][k] != -1)
        {
            return dp[curr + 1000][k];
        }

        long long a = solve(curr + 1, t, k - 1);

        a += solve(curr - 1, t, k - 1);

        return dp[curr + 1000][k] = a % 1000000007;
    }

    int numberOfWays(int startPos, int endPos, int k)
    {
        memset(dp, -1, sizeof(dp));

        long long ans = solve(startPos, endPos, k);
        return ans % 1000000007;
    }
};