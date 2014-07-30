class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int index = 1;
        int start = 0;
        int half = n / 2;
        while (start < half) {
            int i = start, j = start;
            while (j < n - 1) {
                matrix[i][j++] = index ++;
            }
            while (i < n - 1) {
                matrix[i++][j] = index ++;
            }
            while (j > start) {
                matrix[i][j--] = index ++;
            }
            while (i > start) {
                matrix[i--][j] = index ++;
            }
            start++;
            n--;
        }
        for (int i = start; i < n; i++) {
            for (int j = start; j < n; j++) {
                matrix[i][j] = index ++;
            }
        }
        return matrix;
    }
};