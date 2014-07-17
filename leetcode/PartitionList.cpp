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
    ListNode *partition(ListNode *head, int x) {
        ListNode *dummy = new ListNode (0);
        dummy->next = head;
        ListNode *prev = dummy, *small = dummy;
        while (head) {
            if (x > head->val) {
                prev->next = head->next;
                head->next = small->next;
                small->next = head;
                small = head;
            }
            prev = head;
            head = head->next;
        }
        return dummy->next;
    }
};