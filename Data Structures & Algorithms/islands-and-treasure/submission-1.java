class Solution {
    public void islandsAndTreasure(int[][] grid) {
        Deque<int[]> deque = new ArrayDeque<>();
        for (int i = 0; i < grid.length; ++i) {
            for (int j = 0; j < grid[i].length; ++j) {
                if (grid[i][j] == 0) {
                    deque.addLast(new int[]{i, j});
                }
            }
        }
        int[][] directions = {
            {1, 0}, {-1, 0},
            {0, 1}, {0, -1}
        };
        while (!deque.isEmpty()) {
            int[] curr = deque.removeFirst();
            int r = curr[0];
            int c = curr[1];
            for (var dir: directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                if (nr < 0 || nr >= grid.length ||
                    nc < 0 || nc >= grid[0].length ||
                    grid[nr][nc] != Integer.MAX_VALUE)
                    continue;
                grid[nr][nc] = grid[r][c] + 1;
                deque.addLast(new int[]{nr, nc});
            }
        }
    }
}
