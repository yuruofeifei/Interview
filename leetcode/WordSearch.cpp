class Solution {
public:
    bool search(vector<vector<char> > &board, int x, int y, string &word, int index, bool **visited) {
        if (!visited[y][x] && board[y][x] == word[index]) {
            if (index == word.size() - 1) 
                return true;
            if (x < board[0].size() - 1) {
                visited[y][x] = true;
                if (search(board, x + 1, y, word, index + 1, visited)) {
                    return true;
                }
                visited[y][x] = false;
            }
                    
            if (x > 0) {
                visited[y][x] = true;
                if (search(board, x - 1, y, word, index + 1, visited)) {
                    return true;
                }
                visited[y][x] = false;
            }
            if (y < board.size() - 1) {
                visited[y][x] = true;
                if (search(board, x, y + 1, word, index + 1, visited)) 
                    return true;
                visited[y][x] = false;
            }
            if (y > 0) {
                visited[y][x] = true;
                if (search(board, x, y - 1, word, index + 1, visited)) 
                    return true;
                visited[y][x] = false;
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char> > &board, string word) {
        if (board.size() == 0) return false;
        if (board[0].size() == 0) return false;
        bool **visited = new bool *[board.size()];
        for (int i = 0; i < board.size(); i++) {
            visited[i] = new bool[board[i].size()];
            for (int j = 0; j < board[i].size(); j++) {
                visited[i][j] = false;
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (search(board, j, i, word, 0, visited)) 
                    return true;
            }
        }
        return false;
    }
};