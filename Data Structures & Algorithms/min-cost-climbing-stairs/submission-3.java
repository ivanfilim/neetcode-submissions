class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        if (n == 1) return cost[0];
        int[] minCost = new int[n];
        for (int i = 2; i < n; ++i) {
            minCost[i] = Math.min(
                minCost[i - 1] + cost[i - 1],
                minCost[i - 2] + cost[i - 2]
            );
        }
        return Math.min(minCost[n - 2] + cost[n - 2], minCost[n - 1] + cost[n - 1]);   
    }
}
