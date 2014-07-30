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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        int i = 1;
        while (i < m) {
            prev = prev->next;
            head = head->next;
            i++;
        }
        while (i < n) {
            head = head->next;
            i++;
        }
        while (prev->next != head) {
            ListNode *l = prev->next;
            prev->next = l->next;
            l->next = head->next;
            head->next = l;
        }
        return dummy->next;
    }
};