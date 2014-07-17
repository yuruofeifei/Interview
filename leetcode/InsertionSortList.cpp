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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        while (head) {
            ListNode *start = dummy->next;
            ListNode *pre = dummy;
            ListNode *next = head->next;
            while (head->val > start->val) {
                start = start->next;
                pre = pre->next;
            }
            prev->next = head->next;
            head->next = pre->next;
            pre->next = head;
            
            if (prev->next == head) prev = head;
            head = next;
        }
        return dummy->next;
    }
};