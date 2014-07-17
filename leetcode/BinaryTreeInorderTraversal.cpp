/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> v;
        if (!root) return v;
        vector<TreeNode *> stack;
        stack.push_back(root);
        while (!stack.empty()) {
            TreeNode *node = stack.back();
            stack.pop_back();
            if (node->right) stack.push_back(node->right);
            if (!node->right && !node->left) v.push_back(node->val);
            else stack.push_back(node);
            if (node->left) stack.push_back(node->left);
            node->left = NULL; node->right = NULL;
        }
        return v;
    }
};