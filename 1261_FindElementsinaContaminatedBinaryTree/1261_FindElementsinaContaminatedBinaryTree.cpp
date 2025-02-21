#include<iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class FindElements {
public:
    unordered_set<int> value;

    void recover(TreeNode* node, int val)
    {
        if (!node)
            return;
        node->val = val;
        value.insert(val);
        recover(node->left, (node->val * 2) + 1);
        recover(node->right, (node->val * 2) + 2);
    }

    FindElements(TreeNode* root) {
        if (root)
            recover(root, 0);
    }

    bool find(int target) {
        bool ans = false;

        for (unordered_set<int> ::iterator i = value.begin(); i != value.end(); i++)
            cout << *i << " ";
        cout << endl;

        if (value.find(target) != value.end())
        {
            cout << target << endl;
            ans = true;
        }
        return ans;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */