#include <bits/stdc++.h>
using namespace std;

// solution

class ThroneInheritance
{
public:
    unordered_map<string, vector<string>> map;
    unordered_set<string> set;
    string king;

    void dfs(const string &root, vector<string> &result)
    {
        if (set.find(root) == set.end())
        {
            result.push_back(root);
        }

        for (const string &child : map[root])
        {
            dfs(child, result);
        }
    }

    ThroneInheritance(string kingName)
    {
        map[kingName] = vector<string>();
        king = kingName;
    }

    void birth(string parentName, string childName)
    {
        map[parentName].push_back(childName);
        map[childName] = vector<string>();
    }

    void death(string name)
    {
        set.insert(name);
    }

    vector<string> getInheritanceOrder()
    {
        vector<string> result;
        dfs(king, result);
        return result;
    }
};
