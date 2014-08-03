class Solution {
public:
    int numDistinct(string S, string T) {
        if (T.empty() || S.empty()) return 0;
        if (T.size() > S.size()) return 0;
        int dp[T.size()][S.size()];
        int count = 0;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == T[0]) count ++;
            dp[0][i] = count;
        } 
        for (int i = 1; i < T.size(); i++) {
            count = 0;
            for (int j = i; j < S.size(); j++) {
                if (S[j] == T[i]) count += dp[i - 1][j - 1];
                dp[i][j] =  count;
            }
        }
        return dp[T.size() - 1][S.size() - 1];
    }
};