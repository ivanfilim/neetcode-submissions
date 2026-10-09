class Solution {
    fun minCostClimbingStairs(cost: IntArray): Int {
        for (i in 2 .. cost.size - 1) {
            cost[i] = cost[i] + Math.min(cost[i - 1], cost[i - 2])
        }

        return Math.min(cost[cost.size - 1], cost[cost.size - 2])
    }
}
