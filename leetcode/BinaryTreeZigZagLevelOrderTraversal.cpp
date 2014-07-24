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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > r;
        if (!root) return r;
        bool fromRightToLeft = 0;
        queue<TreeNode *> q;
        q.push(root);
        stack<TreeNode *> s;
        int count = 1;
        r.push_back(vector<int>(1, root->val));
        while (!q.empty()) {
            TreeNode *t = q.front();
            q.pop();
            count --;
            if (fromRightToLeft) {
                if (t->right) s.push(t->right);
                if (t->left) s.push(t->left);
                
            }
            else {
                if (t->left) s.push(t->left);
                if (t->right) s.push(t->right);
            }
            if (count == 0) {
                count = s.size();
                vector<int> v;
                while (!s.empty()) {
                    TreeNode *temp = s.top();
                    q.push(temp); s.pop();
                    v.push_back(temp->val);
                }
                fromRightToLeft = !fromRightToLeft;
                if (v.size() > 0)
                    r.push_back(v);
            }
        }
        return r;
    }
};