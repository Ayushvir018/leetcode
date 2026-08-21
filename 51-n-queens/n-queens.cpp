class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;

    void solve(int r, int n, int col, int d1, int d2) {
        if (r == n) {
            ans.push_back(board);
            return;
        }

        int available = ((1 << n) - 1) & ~(col | d1 | d2);

        while (available) {
            int bit = available & -available;
            available -= bit;

            int c = __builtin_ctz(bit);
            board[r][c] = 'Q';

            solve(r + 1, n,
                  col | bit,
                  (d1 | bit) << 1,
                  (d2 | bit) >> 1);

            board[r][c] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        solve(0, n, 0, 0, 0);
        return ans;
    }
};