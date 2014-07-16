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
    void path(TreeNode *root, int sum, vector<vector<int>> &ret, vector<int> v) {
        if (root) {
            v.push_back(root->val);
            if (!root->left && !root->right && root->val == sum) {
                ret.push_back(v);
                return ;
            }
            path(root->left, sum - root->val, ret, v);
            path(root->right, sum - root->val, ret, v);
        }
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> ret;
        vector<int> v;
        path(root, sum, ret, v);
        return ret;
    }
};