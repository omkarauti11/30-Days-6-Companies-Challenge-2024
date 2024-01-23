
#include <bits/stdc++.h>
using namespace std;

// solution

#define mod 1000000007

class Solution
{
public:
    long long powMod(long long a, long long b)
    {

        long long result = 1;

        while (b)
        {
            if (b & 1)
            {
                result = (result % mod * a % mod) % mod;
            }

            a = (a % mod * a % mod) % mod;
            b >>= 1;
        }
        return result;
    }

    int minNonZeroProduct(int p)
    {
        long long mx = (1LL << p) - 1;

        return (powMod((mx - 1 + mod) % mod, mx / 2) % mod * (mx % mod)) % mod;
    }
};
