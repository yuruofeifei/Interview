/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode *slow = head, *fast = head;
        for (int i = 0; i < k; i++) {
            if (fast->next) {
                fast = fast->next;
            }
            else {
                fast = head;
            }
        }
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        if (slow == fast) return head;
        ListNode *ret = slow->next;
        fast->next = head;
        slow->next = NULL;
        return ret;
    }
};