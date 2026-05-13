class Solution {
public:
    vector<vector<string>> result;

    bool isSafe(vector<string>& board, int row, int col) {
        int n = board.size();

        // vertical
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        // upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // upper-right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void nQueens(vector<string>& board, int row) {
        int n = board.size();

        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (isSafe(board, row, j)) {
                board[row][j] = 'Q';
                nQueens(board, row + 1);
                board[row][j] = '.'; // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        nQueens(board, 0);
        return result;
    }
};