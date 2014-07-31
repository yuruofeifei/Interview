class Solution {
public:
    int nqueen(int row, int n, int *col) {
        if (row == n) return 1;
        int nSol = 0;
        for (int i = 0; i < n; i++) {
            bool todo = true;
            for (int j = 0; j < row; j++) {
                if (col[j] == i || abs(col[j] - i) == abs(row - j)) {todo = false; break;}
            }
            if (!todo) continue;
            col[row] = i;
            nSol += nqueen(row + 1, n, col);
            col[row] = -1;
        }
        return nSol;
    }
    int totalNQueens(int n) {
        int col[n];
        for (int i = 0; i < n; i++) col[i] = -1;
        return nqueen(0, n, col);
    }
};