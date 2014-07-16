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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> r;
        if (!root) return r;
        vector<TreeNode *> stack;
        stack.push_back(root);
        while (stack.size() > 0) {
            TreeNode *n = stack.back();
            stack.pop_back();
            r.push_back(n->val);
            if (n->left) stack.push_back(n->left);
            if (n->right) stack.push_back(n->right);
            
        }
        reverse(r.begin(), r.end());
        return r;
    }
};