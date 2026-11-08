class Solution {
    public int orangesRotting(int[][] grid) {
        int time = 0;
        int freshCounter = 0;
        Deque<int[]> deque = new ArrayDeque<>();
        for (int i = 0; i < grid.length; ++i) {
            for (int j = 0; j < grid[i].length; ++j) {
                if (grid[i][j] == 2) {
                    deque.addLast(new int[] {i, j});
                } else if (grid[i][j] == 1) {
                    ++freshCounter;
                }
            }
        }
        int[][] directions = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} }; 
        while (!deque.isEmpty()) {
            List<int[]> rottenOranges = new ArrayList<>();
            while (!deque.isEmpty()) {
                rottenOranges.add(deque.removeFirst());
            }
            boolean timeElapsed = false;
            for (int[] rottenOrange: rottenOranges) {
                for (int[] dir: directions) {
                    int r = rottenOrange[0] + dir[0];
                    int c = rottenOrange[1] + dir[1];
                    if (r < 0 || r >= grid.length ||
                        c < 0 || c >= grid[0].length ||
                        grid[r][c] != 1)
                        continue;
                    timeElapsed = true;
                    --freshCounter;
                    grid[r][c] = 2;
                    deque.addLast(new int[] {r, c});
                }
            }
            if (timeElapsed) ++time;
        }
        if (freshCounter > 0) return -1;
        else return time;
    }
}
