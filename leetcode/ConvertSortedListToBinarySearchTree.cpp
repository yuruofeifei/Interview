/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) return NULL;
        if (!head->next) return new TreeNode(head->val);
        if (!head->next->next) {
            TreeNode *root = new TreeNode(head->val);
            root->right = new TreeNode(head->next->val);
        }
        ListNode *prev;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast) {
            prev = slow;
            slow = slow->next;
            if (fast->next)
                fast = fast->next->next;
            else 
                fast = fast->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        prev->next = NULL;
        if (slow != head) root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
    
};