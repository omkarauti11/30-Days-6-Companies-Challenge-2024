
#include <bits/stdc++.h>
using namespace std;

// solution

class Solution
{
public:
    void computeLPS(string pattern, vector<int> &lps)
    {
        int M = pattern.length();
        int len = 0; // Length of the previous longest prefix & suffix

        lps[0] = 0; // Because there is no proper suffix and prefix of pattern[0..0]

        int i = 1;
        while (i < M)
        {
            if (pattern[i] == pattern[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    vector<int> KMP(string pat, string txt)
    {
        int N = txt.length();
        int M = pat.length();
        vector<int> result;

        // Create an LPS array to store the longest proper prefix which is also a suffix
        // lps[i] = the longest proper prefix of pat[0..i] which is also a suffix of pat[0..i].
        vector<int> lps(M, 0);
        computeLPS(pat, lps);

        int i = 0; // Index for text
        int j = 0; // Index for pattern

        while (i < N)
        {
            if (pat[j] == txt[i])
            {
                i++;
                j++;
            }

            if (j == M)
            {
                result.push_back(i - j); // Pattern found at index i-j+1 (If you have to return 1 Based indexing, that's why added + 1)
                j = lps[j - 1];
            }
            else if (i < N && pat[j] != txt[i])
            {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }

        return result;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k)
    {
        int n = s.length();

        vector<int> i_indices = KMP(a, s);
        vector<int> j_indices = KMP(b, s);
        /*
            Just simply find the indices where a is present in s
            Just simply find the indices where b is present in s
        */

        vector<int> result;

        for (int &i : i_indices)
        {
            /*
                For every index i where 'a' was found in 's'
                I will see if we find any index j in the range i-k and i+k
            */

            int left_limit = max(0, i - k);      // To avoid out of bound -> I used max(0, i-k)
            int right_limit = min(n - 1, i + k); // To avoid out of bound -> I used min(n-1, i+k)

            auto it = lower_bound(begin(j_indices), end(j_indices), left_limit);

            if (it != j_indices.end() && *it <= right_limit)
            {
                result.push_back(i);
            }
        }

        return result;
    }
};