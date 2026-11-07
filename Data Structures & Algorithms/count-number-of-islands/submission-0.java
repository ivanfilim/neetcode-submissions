class Solution {
    public int numIslands(char[][] grid) {
        int counter = 0;
        for (int i = 0; i < grid.length; ++i) {
            for (int j = 0; j < grid[i].length; ++j) {
                if (grid[i][j] == '1')
                    ++counter;
                    visitLand(grid, i, j);
            }
        }
        return counter;
    }

    private void visitLand(char[][] grid, int i, int j) {
        if (i < 0 || 
            j < 0 || 
            i > grid.length - 1 || 
            j > grid[i].length - 1 ||
            grid[i][j] == '0') return;
        grid[i][j] = '0';
        visitLand(grid, i + 1, j);
        visitLand(grid, i - 1, j);
        visitLand(grid, i, j - 1);
        visitLand(grid, i, j + 1);
    }
}
