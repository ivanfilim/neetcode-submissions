class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        prev, prevPrev = cost[1], cost[0]
        for i in range(2, len(cost)):
            curr = cost[i] + min(prev, prevPrev)
            prevPrev = prev
            prev = curr
        return min(prev, prevPrev)