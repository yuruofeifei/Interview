class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        bool dp[s1.size() + 1][s2.size() + 1];
        dp[0][0] = true;
        for (int i = 1; i <= s1.size(); i++) {
            dp[i][0] = false;
            if (s1[i - 1] == s3[i - 1])
                dp[i][0] = dp[i - 1][0]; 
        }
        for (int i = 1; i <= s2.size(); i++) {
            dp[0][i] = false;
            if (s2[i - 1] == s3[i - 1])
                dp[0][i] = dp[0][i - 1]; 
        }
        for (int i = 1; i <= s1.size(); i++) {
            for (int j = 1; j <= s2.size(); j++) {
                dp[i][j] = false;
                if (s1[i - 1] == s3[i + j - 1]) {
                    dp[i][j] |= dp[i - 1][j];
                }
                if (s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] |= dp[i][j - 1];
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};