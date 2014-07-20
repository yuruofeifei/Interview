class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0) return 0;
        int dp[s.size() + 1];
        for (int i = 0; i <= s.size(); i++) {
            dp[i] = 0;
        }
        dp[0] = 1;
        for (int i = 0; i < s.size(); i++) {
            if (stoi(s.substr(i, 1)) != 0) {
                dp[i + 1] += dp[i];
            }
            if (i == 0) continue;
            if (stoi(s.substr(i - 1, 2)) >= 10 && stoi(s.substr(i - 1, 2)) <= 26) {
                    dp[i + 1] += dp[i - 1];
            }
        }
        return dp[s.size()];
    }
};