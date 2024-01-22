
#include <bits/stdc++.h>
using namespace std;

// solution

class Solution
{
public:
    int maximizeSquareHoleArea(int n, int m, vector<int> &hBars, vector<int> &vBars)
    {

        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int ans1 = 1;
        int ans2 = 1;

        int ct = 1;

        for (int i = 0; i < hBars.size() - 1; i++)
        {

            if (hBars[i + 1] == hBars[i] + 1)
            {
                ct++;
                ans1 = max(ans1, ct);
            }
            else
            {
                ct = 1;
            }
        }

        ct = 1;

        for (int i = 0; i < vBars.size() - 1; i++)
        {

            if (vBars[i + 1] == vBars[i] + 1)
            {
                ct++;
                ans2 = max(ans2, ct);
            }
            else
            {
                ct = 1;
            }
        }

        int ans = min(ans2 + 1, ans1 + 1);

        return ans * ans;
    }
};