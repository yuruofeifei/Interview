class Solution {
public:
    bool solve(vector<vector<char>> &board, int index) {
        if (index == 81) {
            return true;
        }
        int temp[9];
        int row = index / 9, col = index % 9;
        if (board[row][col] == '.') {
            for (int i = 1; i <= 9; i++) {
                board[row][col] = i + '0';
                bool valid = true;
                for (int j = 0; j < 9; j++) {
                    temp[j] = 0;
                }
                for (int j = 0; j < 9; j++) {
                    if (board[row][j] == '.') continue;
                    int b = board[row][j] - '1';
                    temp[b] ++;
                    if (temp[b] > 1) {
                        valid = false;
                    }
                }
                for (int j = 0; j < 9; j++) {
                    temp[j] = 0;
                }
                for (int j = 0; j < 9; j++) {
                    if (board[j][col] == '.') continue;
                    int b = board[j][col] - '1';
                    temp[b] ++;
                    if (temp[b] > 1) {
                        valid = false;
                    }
                }
                for (int j = 0; j < 9; j++) {
                    temp[j] = 0;
                }
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        if (board[3 * (row / 3) + j][3 * (col / 3) + k] == '.') continue;
                        int b = board[3 * (row / 3) + j][3 * (col / 3) + k] - '1';
                        temp[b] ++;
                        if (temp[b] > 1) {
                            valid = false;
                        }
                    }
                }
                if (valid) {
                    if (solve(board, index + 1)) return true;
                }
                board[row][col] = '.';
            }
            return false;
        }
        else {
            return solve(board, index + 1);
        }
    }
    void solveSudoku(vector<vector<char> > &board) {
        int index = 0;
        solve(board, index);
    }
};