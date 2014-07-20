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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val > l2->val) { l2->next = mergeTwoLists(l1, l2->next); return l2;}
        else {l1->next = mergeTwoLists(l1->next, l2); return l1; }
    }
    ListNode *sortList(ListNode *head) {
        if (!head) return NULL;
        queue<ListNode *> q;
        while (head) {
            q.push(head);
            ListNode *prev = head;
            head = head->next;
            prev->next = NULL;
        }
        while (q.size() > 1) {
            ListNode *l = q.front();
            q.pop();
            ListNode *r = q.front();
            q.pop();
            q.push(mergeTwoLists(l, r));
        }
        
        return q.front();
        
    }
};