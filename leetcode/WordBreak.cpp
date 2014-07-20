class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        bool *dp = new bool[s.size() + 1];
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            dp[i] = false;
        }
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j <= i; j++) {
                if (dp[j]) {
                    if (dict.find(s.substr(j, i + 1 - j)) != dict.end()) {
                        dp[i + 1] = true;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};