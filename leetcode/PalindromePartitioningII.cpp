class Solution {
public:
    int minCut(string s) {
        int dp[s.size()];
        for (int i = 0; i <= s.size(); i++) {
            dp[i] = i - 1;
        }
        bool **sub = new bool*[s.size()];
        for (int i = 0; i < s.size(); i++) {
            sub[i] = new bool[s.size()];
            for (int j = 0; j < s.size(); j++) {
                sub[i][j] = false;
            }
        }
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (s[j] == s[i - 1]) {
                    if (j == i - 1 || i - 2 == j || sub[j + 1][i - 2]) {
                        sub[j][i - 1] = true;
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }    
        return dp[s.size()];
    }
};