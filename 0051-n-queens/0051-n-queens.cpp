class Solution {
private:
    bool canFill(int row, int col, vector<string>& board, int n) {

        // Check same row on the left
        for (int j = 0; j < col; j++) {
            if (board[row][j] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {

            if (board[i][j] == 'Q')
                return false;
        }

        // Check lower-left diagonal
        for (int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--) {

            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }
    void f(int col, int n, vector<vector<string>>& ans, vector<string>& board) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (canFill(row, col, board, n)) {
                board[row][col] = 'Q';
                f(col + 1, n, ans, board);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        f(0, n, ans, board);
        return ans;
    }
};