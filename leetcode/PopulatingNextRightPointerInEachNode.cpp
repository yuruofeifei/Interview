/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode *> q;
        q.push(root);
        int remaining = 1;
        int nextLevelCount = 0;
        TreeLinkNode *prev = NULL;
        while (!q.empty()) {
            TreeLinkNode *n = q.front();
            q.pop();
            if (!prev) {
                prev = n;
            }
            else {
                prev->next = n;
                prev = prev->next;
            }
            remaining --;
            if (n->left) {
                nextLevelCount ++;
                q.push(n->left);
            }
            if (n->right) {
                nextLevelCount ++;
                q.push(n->right);
            }
            if (remaining == 0) {
                remaining = nextLevelCount;
                nextLevelCount = 0;
                prev = NULL;
            }
        }
    }
};