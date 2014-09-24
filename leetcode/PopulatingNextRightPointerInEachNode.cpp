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
        int current = 1, next = 0;
        TreeLinkNode *prev = NULL;
        while (!q.empty()) {
            TreeLinkNode *n = q.front(); q.pop();
            if (prev) prev->next = n;
            prev = n;
            current --;
            if (n->left) {q.push(n->left); next++;}
            if (n->right) {q.push(n->right); next++;}
            if (current == 0) {
                current = next;
                next = 0;
                prev = NULL;
            }
        }
    }
};
