class Solution {
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        boolean[][] visitedPacific = new boolean[heights.length][heights[0].length];
        boolean[][] visitedAtlantic = new boolean[heights.length][heights[0].length];

        final Deque<int[]> canReachPacific = new ArrayDeque<>();
        for (int i = 0; i < heights.length; ++i) {
            visitedPacific[i][0] = true;
            canReachPacific.addLast(new int[] {i, 0});
        }
        for (int i = 0; i < heights[0].length; ++i) {
            visitedPacific[0][i] = true;
            canReachPacific.addLast(new int[] {0, i});
        }
        
        final Deque<int[]> canReachAtlantic = new ArrayDeque<>();
        for (int i = 0; i < heights.length; ++i) {
            visitedAtlantic[i][heights[0].length - 1] = true;
            canReachAtlantic.addLast(new int[] {i, heights[0].length - 1});
        }
        for (int i = 0; i < heights[0].length; ++i) {
            visitedAtlantic[heights.length - 1][i] = true;
            canReachAtlantic.addLast(new int[] {heights.length - 1, i});
        }
        
        final int[][] directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

        final Set<List<Integer>> pacificReachable = new HashSet<>();
        while (!canReachPacific.isEmpty()) {
            int currSize = canReachPacific.size();
            for (int i = 0; i < currSize; ++i) {
                int[] coord = canReachPacific.removeLast();
                pacificReachable.add(List.of(coord[0], coord[1]));
                for (int[] dir: directions) {
                    int[] newCoord = { coord[0] + dir[0], coord[1] + dir[1] };
                    if (newCoord[0] < 0 ||
                        newCoord[1] < 0 ||
                        newCoord[0] >= heights.length ||
                        newCoord[1] >= heights[0].length ||
                        heights[newCoord[0]][newCoord[1]] < heights[coord[0]][coord[1]] ||
                        visitedPacific[newCoord[0]][newCoord[1]]) {
                        continue;
                    }
                    visitedPacific[newCoord[0]][newCoord[1]] = true;
                    canReachPacific.addFirst(newCoord);
                }
            }
        }

        final Set<List<Integer>> atlanticReachable = new HashSet<>();
        while (!canReachAtlantic.isEmpty()) {
            int currSize = canReachAtlantic.size();
            for (int i = 0; i < currSize; ++i) {
                int[] coord = canReachAtlantic.removeLast();
                atlanticReachable.add(List.of(coord[0], coord[1]));
                for (int[] dir: directions) {
                    int[] newCoord = { coord[0] + dir[0], coord[1] + dir[1] };
                    if (newCoord[0] < 0 ||
                        newCoord[1] < 0 ||
                        newCoord[0] >= heights.length ||
                        newCoord[1] >= heights[0].length ||
                        heights[newCoord[0]][newCoord[1]] < heights[coord[0]][coord[1]] ||
                        visitedAtlantic[newCoord[0]][newCoord[1]]) {
                        continue;
                    }
                    visitedAtlantic[newCoord[0]][newCoord[1]] = true;
                    canReachAtlantic.addFirst(newCoord);
                }
            }
        }

        return pacificReachable.stream().filter(it -> atlanticReachable.contains(it)).toList();
    }

    private Set<List<Integer>> oceanReachable(
        int[][] heights,
        Deque<int[]> canReachOcean,
        boolean[][] visited
    ) {
        final int[][] directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
        final Set<List<Integer>> reachable = new HashSet<>();
        while (!canReachOcean.isEmpty()) {
            int currSize = canReachOcean.size();
            for (int i = 0; i < currSize; ++i) {
                int[] coord = canReachOcean.removeLast();
                reachable.add(List.of(coord[0], coord[1]));
                for (int[] dir: directions) {
                    int[] newCoord = { coord[0] + dir[0], coord[1] + dir[1] };
                    if (newCoord[0] < 0 ||
                        newCoord[1] < 0 ||
                        newCoord[0] >= heights.length ||
                        newCoord[1] >= heights[0].length ||
                        heights[newCoord[0]][newCoord[1]] < heights[coord[0]][coord[1]] ||
                        visited[newCoord[0]][newCoord[1]]) {
                        continue;
                    }
                    visited[newCoord[0]][newCoord[1]] = true;
                    canReachOcean.addFirst(newCoord);
                }
            }
        }
        return reachable;
    }
}
