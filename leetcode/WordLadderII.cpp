class Solution {
public:
    void generate(string s, vector<string> &v, unordered_map<string, pair<vector<string>, int>> &visited, vector<vector<string>> &ret) {
        if (visited[s].second == 1) {
            reverse(v.begin(), v.end());
            ret.push_back(v);
            reverse(v.begin(), v.end());
            return;
        }
        for (string &str : visited[s].first) {
            v.push_back(str);
            generate(str, v, visited, ret);
            v.pop_back();
        }
    }
    
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> ret;
        queue<string> q;
        q.push(start);
        unordered_map<string, pair<vector<string>, int>> visited;
        visited[start] = make_pair(vector<string>(), 1);
        while (!q.empty()) {
            string s = q.front();
            int step = visited[s].second;
            q.pop();
            for (int i = 0; i < s.size(); i++) {
                string temp = s;
                for (int j = 'a'; j <= 'z'; j++) {
                    if (j == s[i]) continue;
                    temp[i] = j;
                    if (dict.count(temp) == 0 || (visited.count(temp) > 0 && visited[temp].second < step + 1)) continue;
                    if (visited.count(temp) == 0) {
                        visited[temp] = make_pair(vector<string>(), step + 1);
                        q.push(temp);
                    }
                    visited[temp].first.push_back(s);
                }
            }
        }
        vector<string> v = {end};
        generate(end, v, visited, ret);
        return ret;
    }
};
