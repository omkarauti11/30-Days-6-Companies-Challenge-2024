#include <bits/stdc++.h>
using namespace std;

// solution

class Solution
{
public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {

        vector<long long> dp(n + 1, 0);

        long long mod = 1e9 + 7;
        long long noOfPeopleSharingSecret = 0;
        long long ans = 0;

        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {

            long long noOfNewPeopleSharingSecret = dp[max(i - delay, 0)];
            long long noOfPeopleForgettingSecret = dp[max(i - forget, 0)];

            noOfPeopleSharingSecret += (noOfNewPeopleSharingSecret - noOfPeopleForgettingSecret + mod) % mod;

            dp[i] = noOfPeopleSharingSecret;
        }

        for (int i = n - forget + 1; i <= n; i++)
        {
            ans = (ans + dp[i]) % mod;
        }

        return static_cast<int>(ans);
    }
};