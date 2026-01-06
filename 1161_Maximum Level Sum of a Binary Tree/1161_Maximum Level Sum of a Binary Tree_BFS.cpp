/*
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
    int maxLevelSum(TreeNode *root)
    {
        queue<TreeNode *> bfs;
        bfs.push(root);

        int level = 1;
        int bestlevel = 1;
        long long maxSum = root->val;
        // cout << level << " " << maxSum << endl;

        while (!bfs.empty())
        {
            long long sum = 0;
            int size = bfs.size();
            bool check = false;
            // cout << size << " ";

            for (int i = 0; i < size; i++)
            {
                TreeNode *cur = bfs.front();
                bfs.pop();

                if (cur->left != nullptr)
                {
                    sum += cur->left->val;
                    bfs.push(cur->left);
                    check = true;
                }
                if (cur->right != nullptr)
                {
                    sum += cur->right->val;
                    bfs.push(cur->right);
                    check = true;
                }
            }
            level++;
            cout << level << " " << sum << endl;
            if (sum > maxSum && check)
            {
                maxSum = sum;
                bestlevel = level;
            }
        }

        return bestlevel;
    }
};