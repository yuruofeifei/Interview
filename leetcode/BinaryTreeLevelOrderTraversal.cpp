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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> ret;
        if (!root) return ret;
        list<TreeNode *> queue;
        queue.push_back(root);
        int remain = 1;
        int nextLevelCount = 0;
        vector<int> v;
        while (!queue.empty()) {
            TreeNode *node = queue.front();
            v.push_back(node->val);
            queue.pop_front();
            remain --;
            if (node->left) {queue.push_back(node->left); nextLevelCount ++;}
            if (node->right) {queue.push_back(node->right); nextLevelCount ++;}
            if (remain == 0) {
                remain = nextLevelCount;
                nextLevelCount = 0;
                ret.push_back(v);
                v.clear();
            }
        }
        return ret;
    }
};