class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        final Map<Integer, Set<Integer>> prerequisitesMap = new HashMap<>();
        for (int i = 0; i < prerequisites.length; ++i) {
            prerequisitesMap.computeIfAbsent(
                prerequisites[i][0],
                key -> new HashSet<>()
            ).add(prerequisites[i][1]);
        }
        int[] state = new int[numCourses];
        for (int course = 0; course < numCourses; ++course) {
            if (!dfs(course, prerequisitesMap, state)) {
                return false;
            }
        }
        return true;
    }

    private boolean dfs(
        int course,
        Map<Integer, Set<Integer>> graph,
        int[] state
    ) {
        if (state[course] == 1) {
            return false;
        }

        if (state[course] == 2) {
            return true;
        }

        state[course] = 1;

        for (int prerequisite : graph.getOrDefault(course, Set.of())) {
            if (!dfs(prerequisite, graph, state)) {
                return false;
            }
        }

        state[course] = 2;
        return true;
    }
}
