
#include <bits/stdc++.h>
using namespace std;

// solution

string encode(string src)
{
    

    char curr = src[0];
    int count = 0;
    int length = src.size();
    string ans = "";

    for (auto it : src)
    {
        if (it == curr)
        {
            count++;
        }
        else
        {
            ans += curr + to_string(count);
            curr = it;
            count = 1;
        }
    }

    ans += curr + to_string(count);
    return ans;
}