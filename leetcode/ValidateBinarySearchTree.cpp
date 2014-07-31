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
    bool validate(TreeNode *root, int min, int max) {
        if (!root) return true;
        if (root->val >= max || root->val <= min) return false;
        return validate(root->left, min, root->val) && validate(root->right, root->val, max);
    }
    bool isValidBST(TreeNode *root) {
        return validate(root, numeric_limits<int>::min(), numeric_limits<int>::max());
    }
};