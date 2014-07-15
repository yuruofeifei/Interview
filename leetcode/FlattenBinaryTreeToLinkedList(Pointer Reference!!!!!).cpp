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
    void connect(TreeNode *root, TreeNode *&l, TreeNode *&r) {
        if (!root) {
            l = NULL; r = NULL;
            return ;
        }
        TreeNode *ll = NULL, *lr = NULL, *rl = NULL, *rr = NULL;
        connect(root->left, ll, lr);
        connect(root->right, rl, rr);
        root->left = NULL;
        l = root; r = root;
        if (ll) { root->right = ll; lr->right = rl;  r = lr; }
        if (rl) { r = rr; }
    }
    void flatten(TreeNode *root) {
        TreeNode *l, *r;
        return connect(root, l, r);
    }
};