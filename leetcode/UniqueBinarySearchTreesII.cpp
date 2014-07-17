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
    void copyAssign(TreeNode *src, TreeNode *&dst, int &index) {
        if (!src) { dst = NULL; return ;}
        dst = new TreeNode(0);
        copyAssign(src->left, dst->left, index);
        dst->val = index ++;
        copyAssign(src->right, dst->right, index);
    }
    
    void generate(int index, int n, vector<vector<TreeNode *>> &ret) {
        if (index > n) {
            return ;
        }
        vector<TreeNode *> v;
        for (int i = 0; i < index; i++) {
            vector<TreeNode *>&l = ret[i]; vector<TreeNode *> &r = ret[index - 1 - i];
            for (int j = 0; j < l.size(); j++) {
                for (int k = 0; k < r.size(); k++) {
                    TreeNode *root_ = new TreeNode(index);
                    root_->left = l[j]; root_->right = r[k];
                    TreeNode *ll, *rr; 
                    int index = 1;
                    copyAssign(l[j], ll, index);
                    TreeNode *root = new TreeNode(index ++);
                    copyAssign(r[k], rr, index);
                    root->left = ll; root->right = rr;
                    v.push_back(root);
                }
            }
        }
        ret.push_back(v);
        generate(index + 1, n, ret);
    }
    vector<TreeNode *> generateTrees(int n) {
        vector<vector<TreeNode *>> ret;
        ret.push_back({NULL});
        ret.push_back({new TreeNode(1)});
        generate(2, n, ret);
        return ret[n];
    }
};