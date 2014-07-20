/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    static bool comp(pair<int, int> &i, pair<int, int> &j) {
        return i.first > j.first;
    }
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;
        vector<pair<int, int>> heap;
        ListNode *heads[lists.size()];
        for (int i = 0; i < lists.size(); i++) {
            heads[i] = lists[i];
            if (heads[i])
                heap.push_back(make_pair(heads[i]->val, i));
        }
        make_heap(heap.begin(), heap.end(), comp);
        while (!heap.empty()) {
            pop_heap(heap.begin(), heap.end(), comp);
            int i = heap.back().second;
            heap.pop_back();
            head->next = heads[i];
            heads[i] = heads[i]->next;
            head = head->next;
            if (heads[i]) {
                heap.push_back(make_pair(heads[i]->val, i));
                push_heap(heap.begin(), heap.end(), comp);
            }
        }
        return dummy->next;
    }
};