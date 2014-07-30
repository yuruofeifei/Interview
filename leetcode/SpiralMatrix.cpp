class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> v;
        int m = matrix.size();
        if (m == 0) return v;
        int n = matrix[0].size();
        int start = 0;
        int half = min(m, n) / 2;
        while (start < half) {
            int i = start, j = start;
            while (j < n - 1) {
                v.push_back(matrix[i][j++]);
            }
            while (i < m - 1) {
                v.push_back(matrix[i++][j]);
            }
            while (j > start) {
                v.push_back(matrix[i][j--]);
            }
            while (i > start) {
                v.push_back(matrix[i--][j]);
            }
            start++;
            m--; n--;
        }
        for (int i = start; i < m; i++) {
            for (int j = start; j < n; j++) {
                v.push_back(matrix[i][j]);
            }
        }
        return v;
    }
};