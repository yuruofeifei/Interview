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
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int start, int end, int index) {
        if (start > end) return NULL;
        int i = 0;
        while (inorder[start + i] != preorder[index]) {
            i++;    
        }
        TreeNode *root = new TreeNode (preorder[index]);
        root->left = build(preorder, inorder, start, start + i - 1, index + 1);
        root->right = build(preorder, inorder, start + i + 1, end, index + i + 1);
        return root;
    }
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty()) return NULL;
        return build(preorder, inorder, 0, inorder.size() - 1, 0);
    }
};