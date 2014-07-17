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
    ListNode *remove(ListNode *head, int n, int &i) {
        if (head == 0) {
            i = 0;
            return NULL;
        }
        ListNode * l = remove(head->next, n, i);
        i++;
        if (i == n) { head->next = NULL; return l;}
        else {head->next = l; return head;}
    }
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int i = 0;
        return remove(head, n, i);
    }
};