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
    bool balanced(TreeNode *root, int &h) {
        if (root == NULL) {
            h = 0;
            return true;
        }
        int lh, rh;
        bool lcheck = balanced(root->left, lh);
        bool rcheck = balanced(root->right, rh);
        h = max(lh, rh) + 1;
        return abs(lh - rh) <= 1 && lcheck && rcheck;
    }
    bool isBalanced(TreeNode *root) {
        int h;
        return balanced(root, h);
    }
};