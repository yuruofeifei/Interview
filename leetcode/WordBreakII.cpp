class Solution {
public:
    void transform(vector<int> *dp, int index, string &s, vector<string> &ret, vector<string> &sub) {
        if (index == 0) {
            string result = "";
            for (int i = sub.size() - 1; i >= 0; i --) {
                result += sub[i];
                if (i != 0)
                    result += " ";
            }
            ret.push_back(result);
            return ;
        }
        for (int i = 0; i < dp[index].size(); i++) {
            sub.push_back(s.substr(dp[index][i], index - dp[index][i]));
            transform(dp, dp[index][i], s, ret, sub);
            sub.pop_back();
        }
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<int> *dp = new vector<int>[s.size() + 1];
        dp[0].push_back(-1);
        
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j <= i; j++) {
                if (!dp[j].empty()) {
                    if (dict.find(s.substr(j, i + 1 - j)) != dict.end()) {
                        dp[i + 1].push_back(j);
                    }
                }
            }
        }
        vector<string> ret;
        vector<string> sub;
        transform(dp, s.size(), s, ret, sub);
        
        return ret;
    }
};