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
        ListNode *temp = head, *start = head;
        for(; head; head = head->next) {
            if (head->val == temp->val) temp->next = head->next;
            else temp = head;
        }
        return start;
    }
};