/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        RandomListNode *start = head;
        while (head) {
            RandomListNode *n = new RandomListNode(head->label);
            n->next = head->next;
            n->random = head->random;
            head->next = n;
            head = head->next->next;
        }
        head = start;
        while (head) {
            if (head->next->random)
                head->next->random = head->next->random->next;
            head = head->next->next;
        }
        head = start;
        RandomListNode *ret = head->next;
        while (head && head->next->next) {
            RandomListNode *next = head->next->next;
            head->next->next = head->next->next->next;
            head->next = next;
            head = head->next;
        }
        head->next = NULL;
        return ret;
    }
};