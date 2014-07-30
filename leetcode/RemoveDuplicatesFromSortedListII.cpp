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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy;
        dummy->next = head;
        while (head) {
            int repeat = 0;
            int val = head->val;
            while (head && head->val == val) {
                repeat ++;
                head = head->next;
            }
            if (repeat > 1) {
                prev->next = head;
            }
            else {
                prev = prev->next;
            }
            
        } 
        return dummy->next;
    }
};