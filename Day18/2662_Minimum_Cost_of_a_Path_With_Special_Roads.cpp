#include <bits/stdc++.h>
using namespace std;

// solution

class Solution
{
public:
    struct comp
    {
        bool operator()(const pair<int, int> &p1, const pair<int, int> &p2)
        {
            return p1.second > p2.second;
        }
    };

    int minimumCost(vector<int> &start, vector<int> &target, vector<vector<int>> &sr)
    {

        map<pair<int, int>, int> mp;
        map<int, pair<int, int>> mp2;

        if (start[0] == target[0] && start[1] == target[1])
        {
            return 0;
        }

        int c = 0;

        if (mp.find({start[0], start[1]}) == mp.end())
        {
            mp[{start[0], start[1]}] = c;
            mp2[c] = {start[0], start[1]};
            c++;
        }

        for (int i = 0; i < sr.size(); i++)
        {
            if (mp.find({sr[i][0], sr[i][1]}) == mp.end())
            {
                mp[{sr[i][0], sr[i][1]}] = c;
                mp2[c] = {sr[i][0], sr[i][1]};
                c++;
            }

            if (mp.find({sr[i][2], sr[i][3]}) == mp.end())
            {
                mp[{sr[i][2], sr[i][3]}] = c;
                mp2[c] = {sr[i][2], sr[i][3]};
                c++;
            }
        }

        if (mp.find({target[0], target[1]}) == mp.end())
        {
            mp[{target[0], target[1]}] = c;
            mp2[c] = {target[0], target[1]};
            c++;
        }

        vector<vector<pair<int, int>>> adj(c);

        for (int i = 0; i < c; i++)
        {
            for (int j = i + 1; j < c; j++)
            {
                adj[i].push_back({j, abs(mp2[i].first - mp2[j].first) + abs(mp2[i].second - mp2[j].second)});
                adj[j].push_back({i, abs(mp2[i].first - mp2[j].first) + abs(mp2[i].second - mp2[j].second)});
            }
        }

        bool flag = 0;

        for (int i = 0; i < sr.size(); i++)
        {
            int u = mp[{sr[i][0], sr[i][1]}];
            int v = mp[{sr[i][2], sr[i][3]}];
            int wt = sr[i][4];

            for (int k = 0; k < adj.size(); k++)
            {
                for (int l = 0; l < adj[k].size(); l++)
                {
                    if (k == u && adj[k][l].first == v)
                    {
                        adj[k][l].second = min(adj[k][l].second, wt);
                    }
                }
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        vector<int> dist(c, INT_MAX);
        dist[mp[{start[0], start[1]}]] = 0;

        pq.push({mp[{start[0], start[1]}], 0});
        vector<bool> vis(c, 0);

        while (!pq.empty())
        {

            int u = pq.top().first;
            vis[u] = 1;
            pq.pop();

            for (int i = 0; i < adj[u].size(); i++)
            {
                int v = adj[u][i].first;
                int wt = adj[u][i].second;
                if (!vis[v] && dist[v] > dist[u] + wt)
                {
                    dist[v] = dist[u] + wt;
                    pq.push({v, dist[v]});
                }
            }
        }

        return dist[mp[{target[0], target[1]}]];
    }
};
