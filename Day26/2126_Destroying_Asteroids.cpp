#include <bits/stdc++.h>
using namespace std;

// solution

class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {
        long long res = mass;
        sort(asteroids.begin(), asteroids.end());

        for (int val : asteroids)
        {
            if (val > res)
            {
                return false;
            }
            else
            {
                res += val;
            }
        }

        return true;
    }
};