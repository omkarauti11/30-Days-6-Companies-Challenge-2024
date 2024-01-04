
#include <bits/stdc++.h>
using namespace std;

// solution

class Solution
{
public:
    vector<pair<int, int>> movements = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool isValid(int x, int y, int n, int m, vector<vector<int>> &isWater)
    {

        if (x >= 0 and x < n and y >= 0 and y < m)
        {
            return true;
        }

        return false;
    }

    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {

        queue<pair<int, int>> q;
        int n = isWater.size();
        int m = isWater[0].size();

        vector<vector<int>> ans(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (isWater[i][j] == 1)
                {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {

            auto v = q.front();
            q.pop();

            int v_x = v.first;
            int v_y = v.second;

            for (auto movement : movements)
            {

                int child_x = movement.first + v_x;
                int child_y = movement.second + v_y;

                if (isValid(child_x, child_y, n, m, isWater))
                {
                    if (ans[child_x][child_y] == -1)
                    {
                        ans[child_x][child_y] = ans[v_x][v_y] + 1;
                        q.push({child_x, child_y});
                    }
                }
            }
        }

        return ans;
    }
};