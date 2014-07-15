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
    TreeNode *convert(vector<int> &num, int start, int end) {
        if (start > end) {
            return NULL;
        }
        TreeNode *root = new TreeNode(num[(start + end) / 2]);
        root->left = convert(num, start, (start + end) / 2 - 1);
        root->right = convert(num, (start + end) / 2 + 1, end);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return convert(num, 0, num.size() - 1);
    }
};