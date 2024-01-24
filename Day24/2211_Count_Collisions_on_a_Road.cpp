
#include <bits/stdc++.h>
using namespace std;

// solution

class Solution
{
public:
    int countCollisions(string directions)
    {

        int ans = 0;
        int r = 0, s = 0, l = 0;

        for (auto x : directions)
        {

            if (x == 'R')
            {
                r++;
            }
            else if (x == 'L')
            {
                l++;

                if (r)
                {
                    ans += 2;
                    ans += (r - 1);
                    r = 0;
                    l = 0;
                    s++;
                }
                else if (s)
                {
                    ans++;
                    r = 0;
                    s++;
                }
            }
            else if (x == 'S')
            {

                s++;

                if (r)
                {
                    ans += r;
                    r = 0;
                }
            }
        }
        return ans;
    }
};
