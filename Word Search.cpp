// Backtracking
// space complexity: O(1)
// time complexity: O(n * m * 4^L) in the worst case;
//n: number of rows in board; m: number of columns in the board; L: the length of the word

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) return false;
        if (board[0].size() == 0) return false;
        // First finding whether there is a letter in the board equals to word[0]; worst case time complexity O(m*n)
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    int c_temp = board[i][j];
                    board[i][j] = '*';
                    // if exists, do depth-first-serch
                    if (helper(board, word, 1, i, j)) return true;
                    board[i][j] = c_temp;
                }
            }
        }
        return false;
    }
    bool helper(vector<vector<char>>& board, string word, int start, int x, int y) {
        if (start == word.size()) {
            return true;
        }
        // for each letter in the word, we need to check four directions; the worse case time complexity is O(4^L);
        vector<int> inc = {-1, 0, 1, 0, -1}; // do the horizon or vertical search, four directions: (-1,0),(0,1),(1,0),(0,-1)
        for (int i=0; i<inc.size()-1; ++i) {
            int x_temp = x + inc[i];
            int y_temp = y + inc[i + 1];
            if (x_temp < 0 || x_temp >= board.size() || y_temp < 0 || y_temp >= board[0].size()) continue;
            if ( board[x_temp][y_temp] == word[start]) {
                int c_temp = board[x_temp][y_temp];
                board[x_temp][y_temp] = '*';
                if (helper(board, word, start + 1, x_temp, y_temp)) return true;
                board[x_temp][y_temp] = c_temp;
            } 
        }
        return false;
    }
};
