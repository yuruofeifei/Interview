class Solution {
public:
    void nqueen(int row, int n, int *col, vector<vector<string>> &ret) {
        if (row == n) {
            vector<string> v;
            for (int i = 0; i < n; i++) {
                string s = "";
                for (int j = 0; j < n; j++) {
                    if (col[i] == j) {
                        s += 'Q';
                    }
                    else {
                        s += '.';
                    }
                }
                v.push_back(s);
            }
            ret.push_back(v);
            return;
        }
        for (int i = 0; i < n; i++) {
            bool todo = true;
            for (int j = 0; j < row; j++) {
                if (col[j] == i || abs(col[j] - i) == abs(row - j)) {todo = false; break;}
            }
            if (!todo) continue;
            col[row] = i;
           nqueen(row + 1, n, col, ret);
            col[row] = -1;
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> ret;
        int col[n];
        for (int i = 0; i < n; i++) col[i] = -1;
        nqueen(0, n, col, ret);
        return ret;
    }
};