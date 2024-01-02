#include <bits/stdc++.h>
using namespace std;

// solution

class Solution
{
public:
    int n, m;
    int i = 0, j = 0;

    Solution(int m, int n)
    {
        this->n = n;
        this->m = m;
    }

    vector<int> flip()
    {

        int I = i, J = j;

        if (j + 1 < n)
        {
            j++;
        }
        else if (i + 1 < m)
        {
            i++;
            j = 0;
        }
        else
        {
            i = 0, j = 0;
        }

        return {I, J};
    }

    void reset()
    {
        // no need of it, we have taken care of it in the flip() part
    }
};
