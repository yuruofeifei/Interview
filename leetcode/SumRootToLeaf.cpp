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
    void sumN(TreeNode *root, int val, int &sum) {
        if (root) { 
            if (!root->left && !root->right) { sum += (10 * val + root->val); return ; }
            sumN(root->left, 10 * val + root->val, sum);
            sumN(root->right, 10 * val + root->val, sum);
        }
        
    }
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        sumN(root, 0, sum);
        return sum;
    }
};