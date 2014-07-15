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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;
        int carry = 0;
        while (l1 && l2) {
            int sum = l1->val + l2->val + carry;
            if (sum >= 10) { sum -= 10; carry = 1; }
            else { carry = 0; }
            head->next = new ListNode(sum);
            head = head->next;
            l1 = l1->next; l2 = l2->next;
        }
        while (l1) {
            int sum = l1->val + carry;
            if (sum >= 10) { sum -= 10; carry = 1; }
            else { carry = 0; }
            head->next = new ListNode(sum);
            head = head->next;
            l1 = l1->next;
        }
        while (l2) {
            int sum = l2->val + carry;
            if (sum >= 10) { sum -= 10; carry = 1; }
            else { carry = 0; }
            head->next = new ListNode(sum);
            head = head->next;
            l2 = l2->next;
        }
        if (carry) head->next = new ListNode(carry);
        return dummy->next;
    }
};