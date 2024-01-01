#include <bits/stdc++.h>
using namespace std;

// Solution

class Solution
{
public:
    int minimizeSet(int d1, int d2, int u1, int u2)
    {
        long long l = 1, r = 2000000009;
        long long ans = r;
        long long lc = (((long long)d1 * (long long)d2)) / __gcd(d1, d2);
        while (l <= r)
        {
            long long mid = (l + r) / 2;
            int x = (int)(mid - (mid / d1));
            int y = (int)(mid - (mid / d2));
            int z = (int)(mid - (mid / lc));
            if (x < u1 || y < u2 || z < u1 + u2)
            {
                l = mid + 1;
            }
            else
            {
                ans = min(ans, mid);
                r = mid - 1;
            }
        }
        return (int)ans;
    }
};