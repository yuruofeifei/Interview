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
    int path(TreeNode *root, int &maxi) {
        if (!root) {
            maxi = 0;
            return numeric_limits<int>::min();
        }
        int lm, rm;
        int l = path(root->left, lm); int r = path(root->right, rm);
        maxi = root->val + max(max(lm, rm), 0);
        return max(max(l, r), root->val + max(lm, 0) + max(rm, 0));
    }
    int maxPathSum(TreeNode *root) {
        int maxi;
        return path(root, maxi);
    }
};