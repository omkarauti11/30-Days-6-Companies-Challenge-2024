#include <bits/stdc++.h>
using namespace std;

// solution

typedef long long ll;
const ll INF = 1e18;
const ll mod1 = 1e9 + 7;
const ll mod2 = 998244353;

class DataStream
{
public:
    map<int, int> m;
    queue<int> q;
    int K;
    int temp;

    DataStream(int value, int k)
    {
        K = k;
        temp = value;
    }

    bool consec(int num)
    {
        q.push(num);
        m[num]++;

        if (q.size() >= K)
        {
            if (q.size() > K)
            {
                m[q.front()]--;
                if (m[q.front()] == 0)
                {
                    m.erase(q.front());
                }
                q.pop();
            }
            if (m.size() == 1 && m[temp] > 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
};
