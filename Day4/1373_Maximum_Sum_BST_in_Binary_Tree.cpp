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
    int result = INT_MIN;

    vector<int> helper(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {INT_MAX, INT_MIN, 0};
        }

        auto left = helper(root->left);
        auto right = helper(root->right);

        if (left[1] >= root->val || right[0] <= root->val)
        {
            return {INT_MIN, INT_MAX, 0};
        }

        int sum = left[2] + root->val + right[2];
        result = max(result, sum);

        return {min(root->val, left[0]), max(root->val, right[1]), sum};
    }

    int maxSumBST(TreeNode *root)
    {
        helper(root);
        return result < 0 ? 0 : result;
    }
};