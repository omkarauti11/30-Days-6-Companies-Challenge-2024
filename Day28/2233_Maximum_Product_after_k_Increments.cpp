
#include <bits/stdc++.h>
using namespace std;

// solution


class Solution {
public:
    int maximumProduct(vector<int>& a, int k) {

        priority_queue<long long, vector<long long>, greater<long long>> q;
        int n = a.size();

        for (int i = 0; i < n; i++) {
            q.push(static_cast<long long>(a[i]));
        }
        
        long long mod = 1000000007;

        while (k > 0) {
            long long val = q.top();
            q.pop();
            q.push((val + 1) % mod);
            k--;
        }

        long long prod = 1;

        while (!q.empty()) {
            prod = (prod * q.top()) % mod;
            q.pop();
        }

        return static_cast<int>(prod);
    }
};