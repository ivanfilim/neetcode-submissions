class Solution {
    public boolean isValidSudoku(char[][] board) {
        final boolean rows[][] = new boolean[9][9];
        final boolean columns[][] = new boolean[9][9];
        final boolean squares[][] = new boolean[9][9];

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char ch = board[r][c];
                if (ch == '.')
                    continue;
                int s = 3 * (r / 3) + c / 3;
                int n = ch - '1';
                if (rows[r][n] || columns[c][n] || squares[s][n])
                    return false;
                rows[r][n] = columns[c][n] = squares[s][n] = true;
            }
        }

        return true;
    }
}