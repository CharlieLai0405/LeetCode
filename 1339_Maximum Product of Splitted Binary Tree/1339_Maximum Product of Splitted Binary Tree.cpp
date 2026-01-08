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
    void dfs(TreeNode *parent, int &count, long long &total)
    {
        if (parent->left != nullptr)
        {
            dfs(parent->left, count, total);
        }
        if (parent->right != nullptr)
        {
            dfs(parent->right, count, total);
        }
        count++;
        total += parent->val;
    }

    long long dfs_subtree(TreeNode *parent, long long &best, long long &total)
    {
        long long left = 0;
        long long right = 0;
        if (parent->left != nullptr)
        {
            left = dfs_subtree(parent->left, best, total);
        }
        if (parent->right != nullptr)
        {
            right = dfs_subtree(parent->right, best, total);
        }

        long long subtree = left + right + parent->val;
        long long temp = subtree * (total - subtree);
        if (temp > best)
            best = temp;

        // cout << best << endl;

        return subtree;
    }

    int maxProduct(TreeNode *root)
    {
        int count = 0;
        long long total = 0;
        long long best = 0;
        dfs(root, count, total);
        // cout << count <<" "<< total << endl;

        long long ans = dfs_subtree(root, best, total);
        cout << ans;

        return best % (1000000000 + 7);
    }
};