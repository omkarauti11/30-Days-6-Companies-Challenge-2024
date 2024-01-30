#include <bits/stdc++.h>
using namespace std;

// solution

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int count = 0;
    vector<int> helper(TreeNode *root, int d)
    {
        if (root == NULL)
        {
            return {0};
        }
        // leaf found
        if (root->left == NULL and root->right == NULL)
        {
            return {1};
        }

        vector<int> left = helper(root->left, d);
        vector<int> right = helper(root->right, d);

        // processing
        for (int x : left)
        {
            for (int y : right)
            {
                if (x > 0 and y > 0)
                    if (x + y <= d)
                    {
                        count += 1;
                    }
                // pair has been found
            }
        }

        vector<int> ans;
        for (int x : left)
        {
            if (x > 0 and x < d)
            {
                ans.push_back(x + 1);
            }
        }

        for (int x : right)
        {
            if (x > 0 and x < d)
            {
                ans.push_back(x + 1);
            }
        }
        return ans;
    }
    int countPairs(TreeNode *root, int distance)
    {
        helper(root, distance);
        return count;
    }
};