class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end) return 1;
        queue<string> q;
        q.push(start);
        unordered_map<string, int> visited;
        visited[start] = 1;
        while (!q.empty()) {
            string s = q.front();
            int step = visited[s];
            q.pop();
            for (int i = 0; i < s.size(); i++) {
                string temp = s;
                for (int j = 'a'; j <= 'z'; j++) {
                    temp[i] = j;
                    if (visited.count(temp) > 0 || dict.count(temp) == 0) continue;
                    if (temp == end) return step + 1;
                    q.push(temp);
                    visited[temp] = step + 1;
                }
            }
        }
        return 0;
    }
};