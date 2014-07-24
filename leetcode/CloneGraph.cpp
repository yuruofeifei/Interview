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
        unordered_map<int, UndirectedGraphNode *> hash;
        queue<UndirectedGraphNode *> q;
        UndirectedGraphNode *ret = new UndirectedGraphNode(node->label);
        hash[node->label] = ret;
        q.push(node);
        while (!q.empty()) {
            UndirectedGraphNode *n = q.front();
            q.pop();
            UndirectedGraphNode *newNode = hash[n->label];
            for (UndirectedGraphNode *adj : n->neighbors) {
                if (hash.find(adj->label) == hash.end()) {
                    hash[adj->label] = new UndirectedGraphNode(adj->label);
                    q.push(adj);
                }
                newNode->neighbors.push_back(hash[adj->label]);
            }
        }
        return ret;
    }
};