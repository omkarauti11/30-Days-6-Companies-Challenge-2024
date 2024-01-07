
#include <bits/stdc++.h>
using namespace std;

// solution

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int bulls = 0;
        vector<int> bucket(10, 0);

        for (int i = 0; i < secret.size(); ++i)
        {
            if (secret[i] == guess[i])
            {
                bulls++;
            }
            else
            {
                bucket[secret[i] - '0']++;
                bucket[guess[i] - '0']--;
            }
        }

        int cows = secret.size() - bulls - accumulate(bucket.begin(), bucket.end(), 0, [](int acc, int x)
                                                      { return acc + (x > 0 ? x : 0); });

        ostringstream result;
        result << bulls << "A" << cows << "B";
        return result.str();
    }
};