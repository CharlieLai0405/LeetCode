/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    pair<long long, TreeNode *> dfs_FindDeep(TreeNode *root, long long curDeep)
    {
        if (root == nullptr)
            return {curDeep, nullptr};

        curDeep++;

        auto left = dfs_FindDeep(root->left, curDeep);
        auto right = dfs_FindDeep(root->right, curDeep);

        if (left.first > right.first)
            return {left.first, left.second};
        else if (right.first > left.first)
            return {right.first, right.second};
        else
            return {left.first, root};
    }
    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        return dfs_FindDeep(root, 0).second;
    }
};