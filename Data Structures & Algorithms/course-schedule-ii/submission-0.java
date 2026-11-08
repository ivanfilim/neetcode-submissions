class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        final Map<Integer, Set<Integer>> prerequisitesMap = new HashMap<>();
        for (int i = 0; i < prerequisites.length; ++i) {
            prerequisitesMap.computeIfAbsent(
                prerequisites[i][0],
                key -> new HashSet<>()
            ).add(prerequisites[i][1]);
        }
        final int[] state = new int[numCourses];
        final List<Integer> res = new ArrayList<>();
        for (int course = 0; course < numCourses; ++course) {
            if (!dfs(course, prerequisitesMap, state, res)) {
                return new int[0];
            }
        }
        return res.stream().mapToInt(Integer::intValue).toArray();
    }

    private boolean dfs(
        int course,
        Map<Integer, Set<Integer>> graph,
        int[] state,
        List<Integer> res
    ) {
        if (state[course] == 1) {
            return false;
        }

        if (state[course] == 2) {
            return true;
        }

        state[course] = 1;

        for (int prerequisite : graph.getOrDefault(course, Set.of())) {
            if (!dfs(prerequisite, graph, state, res)) {
                return false;
            }
        }

        state[course] = 2;
        res.add(course);
        return true;
    }
}
