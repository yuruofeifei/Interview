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
    bool hasPathSum(TreeNode *root, int sum) {
        if (root) {
            if (!root->left && !root->right && sum == root->val) return true;
            return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
        }
        return false;
    }
};