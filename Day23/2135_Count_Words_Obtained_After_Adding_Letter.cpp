
#include <bits/stdc++.h>
using namespace std;

// solution


class Solution {
public:
    int bitmask(const string& word) {
        int res = 0;
        for (char c : word) {
            res += 1 << (c - 'a');
        }
        return res;
    }

    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int ans = 0;
        unordered_set<int> seen;
        for (const auto& word : startWords) {
            seen.insert(bitmask(word));
        }

        for (const auto& word : targetWords) {
            int currentBitmask = bitmask(word);
            for (char c : word) {
                if (seen.find(currentBitmask - (1 << (c - 'a'))) != seen.end()) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
