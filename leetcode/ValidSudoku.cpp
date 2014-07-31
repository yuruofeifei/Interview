class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int col[9];
        int row[9];
        int grid[9];
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                col[j] = 0;
                row[j] = 0;
                grid[j] = 0;
            }
            int r = i / 3, c = i % 3;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    row[board[i][j] - '1'] ++;
                    if (row[board[i][j] - '1'] > 1) return false;
                }
                if (board[j][i] != '.') {
                    col[board[j][i] - '1'] ++;
                    if (col[board[j][i] - '1'] > 1) return false;
                }
                int rr = j / 3, cc = j % 3;
                if (board[3 * r + rr][3 * c + cc] != '.') {
                    grid[board[3 * r + rr][3 * c + cc] - '1'] ++;
                    if (grid[board[3 * r + rr][3 * c + cc] - '1'] > 1) return false;
                }
            }
        }
        return true;
    }
};