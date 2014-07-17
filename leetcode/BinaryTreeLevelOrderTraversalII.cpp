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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> ret;
        if (!root) return ret;
        queue<TreeNode *> q;
        q.push(root);
        int remain = 1;
        int nextLevelCount = 0;
        vector<int> v;
        while (!q.empty()) {
            TreeNode *node = q.front();
            v.push_back(node->val);
            q.pop();
            remain --;
            if (node->left) {q.push(node->left); nextLevelCount ++;}
            if (node->right) {q.push(node->right); nextLevelCount ++;}
            if (remain == 0) {
                remain = nextLevelCount;
                nextLevelCount = 0;
                ret.push_back(v);
                v.clear();
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};