/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        unordered_map<int, UndirectedGraphNode *> map = {{node->label, new UndirectedGraphNode(node->label)}};
        queue<UndirectedGraphNode *> q; q.push(node);
        while (!q.empty()) {
            UndirectedGraphNode *t = q.front(), *r = map[t->label];
            q.pop();
            for (UndirectedGraphNode *n : t->neighbors) {
                if (!map.count(n->label)) { map[n->label] = new UndirectedGraphNode(n->label); q.push(n); }
                r->neighbors.push_back(map[n->label]);
            }
        }
        return map[node->label];
    }
};
