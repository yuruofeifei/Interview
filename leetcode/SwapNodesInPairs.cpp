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
    ListNode *swapPairs(ListNode *head) {
        if (!head) return head;
        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy;
        prev->next = head;
        ListNode *slow = head, *fast = head->next;
        while (fast) {
            ListNode *next = fast->next;
            fast->next = slow;
            slow->next = next;
            prev->next = fast;
            prev = slow;
            slow = slow->next;
            if (!slow) break;
            fast = slow->next;
        }
        return dummy->next;
    }
};