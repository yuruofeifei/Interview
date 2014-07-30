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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        while (head) {
            int i = 1;
            while (i < k) {
                head = head->next;
                if (!head) return dummy->next;
                i++;
            }
            ListNode *next = prev->next;
            while (prev->next != head) {
                ListNode *l = prev->next;
                prev->next = l->next;
                l->next = head->next;
                head->next = l;
            }
            prev = next;
            head = next->next;
        }
        return dummy->next;
    }
};