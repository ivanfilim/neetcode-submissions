class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int res = 0;
        for (int i = 0; i < grid.length; ++i) {
            for (int j = 0; j < grid[i].length; ++j) {
                if (grid[i][j] == 1) {
                    res = Math.max(res, islandArea(grid, i, j));
                }
            }
        }
        return res;
    }

    private int islandArea(int[][] grid, int i, int j) {
        if (i < 0 ||
            j < 0 ||
            i == grid.length ||
            j == grid[i].length ||
            grid[i][j] == 0) {
            return 0;
        } else {
            grid[i][j] = 0;
            return islandArea(grid, i + 1, j) + 
                   islandArea(grid, i - 1, j) +
                   islandArea(grid, i, j + 1) + 
                   islandArea(grid, i, j - 1) + 1;
        }
    }
}