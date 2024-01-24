
#include <bits/stdc++.h>
using namespace std;

// solution

class Solution
{
public:
    long long mod = 1e9 + 7;
    long long goodsubs(vector<long long> &cnt, long long prod, long long val)
    {
        long long value = 0;
        for (long long i = val + 1; i <= 30LL; i++)
        {
            if (cnt[i] > 0 && __gcd(i, prod) == 1LL)
            {
                value += cnt[val] * goodsubs(cnt, prod * i, i);
                value %= mod;
            }
        }
        value += cnt[val];
        return value % mod;
    }
    int numberOfGoodSubsets(vector<int> &nums)
    {

        int n = nums.size();
        vector<long long> cnt(31, 0);
        for (int i = 0; i < n; i++)
        {
            int v = nums[i], c = 0;
            bool check = true;
            while (v % 2 == 0)
            {
                c++;
                v /= 2;
            }
            check &= (c < 2);
            for (int i = 3; i <= sqrt(v); i += 2)
            {
                c = 0;
                while (v % i == 0)
                {
                    c++;
                    v /= i;
                }
                check &= (c < 2);
            }
            if (check)
            {
                cnt[nums[i]]++;
            }
        }
        long long ans = 0;
        for (long long i = 30; i > 1; i--)
        {
            ans += goodsubs(cnt, i, i);
            ans %= mod;
        }
        long long ones = 1, power = 2LL;
        while (cnt[1])
        {
            if (cnt[1] & 1)
            {
                ones *= power;
                ones %= mod;
            }
            power *= power;
            power %= mod;
            cnt[1] >>= 1;
        }
        ans *= ones;
        ans %= mod;
        return ans;
    }
};