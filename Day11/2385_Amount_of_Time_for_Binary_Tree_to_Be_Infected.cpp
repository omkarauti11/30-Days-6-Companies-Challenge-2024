#include <bits/stdc++.h>
using namespace std;



struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// solution

class Solution
{
public:
    void convert(TreeNode *current, int parent, unordered_map<int, vector<int>> &adj)
    {
        if (current == nullptr)
        {
            return;
        }

        if (parent != -1)
        {
            adj[current->val].push_back(parent);
        }

        if (current->left != nullptr)
        {
            adj[current->val].push_back(current->left->val);
        }

        if (current->right != nullptr)
        {
            adj[current->val].push_back(current->right->val);
        }
        convert(current->left, current->val, adj);
        convert(current->right, current->val, adj);
    }

    int amountOfTime(TreeNode *root, int start)
    {

        unordered_map<int, vector<int>> adj;
        convert(root, -1, adj);

        queue<int> que;
        que.push(start);

        unordered_set<int> visited;
        visited.insert(start);

        int minutes = 0;

        while (!que.empty())
        {
            int n = que.size();

            while (n--)
            {
                int curr = que.front();
                que.pop();

                for (int &ngbr : adj[curr])
                {
                    if (visited.find(ngbr) == visited.end())
                    {
                        que.push(ngbr);
                        visited.insert(ngbr);
                    }
                }
            }
            minutes++;
        }

        return minutes - 1;
    }
};