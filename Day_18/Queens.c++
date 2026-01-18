class Solution {
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        backtrack(0, n, board, res);
        return res;
    }

    void backtrack(int r, int n, vector<string>& board, vector<vector<string>>& res) 
    {
        if (r == n) 
        {
            res.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) 
        {
            if (check(r, c, n, board) == 1) 
            {
                board[r][c] = 'Q';
                backtrack(r + 1, n, board, res);
                board[r][c] = '.';
            }
        }
    }

    int check(int r, int c, int n, vector<string>& board) 
    {
        for (int i = 0; i < r; i++) 
        {
            if (board[i][c] == 'Q') return 0;
        }

        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) 
        {
            if (board[i][j] == 'Q') return 0;
        }

        for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++) 
        {
            if (board[i][j] == 'Q') return 0;
        }

        return 1;
    }
};