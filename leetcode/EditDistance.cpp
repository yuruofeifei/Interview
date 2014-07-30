class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty()) return word2.size();
        if (word2.empty()) return word1.size();
        int dp[word1.size() + 1][word2.size() + 1];
        for (int i = 0 ; i <= word1.size(); i++) {
            dp[i][0] = i;
        }
        for (int i = 0 ; i <= word2.size(); i++) {
            dp[0][i] = i;
        }
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                int edit;
                if (word1[i - 1] == word2[j - 1]) edit = 0; else edit = 1;
                dp[i][j] = min(dp[i - 1][j - 1] + edit, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
            }
        }
        return dp[word1.size()][word2.size()];
    }
};