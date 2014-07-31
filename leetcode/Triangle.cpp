class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.empty()) return 0;
        int dp[triangle.back().size()];
        dp[0] = triangle[0][0];
        for (int i = 0; i < triangle.size(); i++) {
            int last = 0;
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0) {
                    last = triangle[i][j] + dp[j];
                }
                else if (j == triangle[i].size() - 1) {
                    dp[j] = triangle[i][j] + dp[j - 1];
                    dp[j - 1] = last;
                }
                else {
                    int v = triangle[i][j] + min(dp[j], dp[j - 1]);
                    dp[j - 1] = last;
                    last = v;
                }
            }
        }
        int v = numeric_limits<int>::max();
        for (int i = 0; i < triangle.back().size(); i++) {
            v = min(v, dp[i]);
        }
        return v;
    }
};