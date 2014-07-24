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
    typedef vector<int>::iterator it;
    TreeNode *build(vector<int> &inorder, vector<int> &postorder, int start, int end, int index) {
        if (start > end) return NULL;
        int i = 0;
        while (inorder[end - i] != postorder[index]) {
            i++;    
        }
        TreeNode *root = new TreeNode (postorder[index]);
        root->right = build(inorder, postorder, end - i + 1, end, index - 1);
        root->left = build(inorder, postorder, start, end - i - 1, index - i - 1);
        return root;
    }
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty()) return NULL;
        return build(inorder, postorder, 0, inorder.size() - 1, inorder.size() - 1);
    }
};