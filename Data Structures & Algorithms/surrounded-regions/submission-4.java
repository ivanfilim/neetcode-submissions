class Solution {
    public void solve(char[][] board) {
        final Deque<int[]> d = new ArrayDeque<>();
        for (int i = 0; i < board.length; ++i) {
            if (board[i][0] == 'O') {
                board[i][0] = 'T';
                d.addLast(new int[]{i, 0});
            }
            if (board[i][board[0].length - 1] == 'O') {
                board[i][board[0].length - 1] = 'T';
                d.addLast(new int[]{i, board[0].length - 1});
            }
        }
        for (int i = 0; i < board[0].length; ++i) {
            if (board[0][i] == 'O') {
                board[0][i] = 'T';
                d.addLast(new int[]{0, i});
            }
            if (board[board.length - 1][i] == 'O') {
                board[board.length - 1][i] = 'T';
                d.addLast(new int[]{board.length - 1, i});
            }
        }
        final int[][] directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
        while (!d.isEmpty()) {
            int[] coord = d.removeFirst();
            for (int[] dir: directions) {
                int[] newCoord = { coord[0] + dir[0], coord[1] + dir[1] };
                if (newCoord[0] >= 0 &&
                    newCoord[0] < board.length &&
                    newCoord[1] >= 0 &&
                    newCoord[1] < board[0].length &&
                    board[newCoord[0]][newCoord[1]] == 'O') {
                        board[newCoord[0]][newCoord[1]] = 'T';
                        d.addLast(newCoord);
                }
            }
            
        }
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                } 
            }
        }
    }
}
