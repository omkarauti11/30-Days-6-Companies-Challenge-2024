#include <bits/stdc++.h>
using namespace std;

// solution

class Solution
{
public:
    long long sumScores(string s)
    {

        int n = s.size();
        vector<int> z(n, n);
        int l = 0, r = 0;
        for (int i = 1, l = 0, r = 0; i < n; i++)
        {

            if (i <= r)
            {
                z[i] = min(r - i + 1, z[i - l]);
            }
            else
            {
                z[i] = 0;
            }

            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            {
                ++z[i];
            }

            if (i + z[i] - 1 > r)
            {
                l = i;
                r = i + z[i] - 1;
            }
        }

        long long sum = 0;

        for (int i = 0; i < s.size(); i++)
        {
            long long x = z[i];
            sum += x;
        }

        return sum;
    }
};