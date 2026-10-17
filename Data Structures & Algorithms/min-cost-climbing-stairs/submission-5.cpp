class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prevPrev = cost[0];
        int prev = cost[1];
        for (int i = 2; i < ssize(cost); ++i) {
            int curr = min(prev, prevPrev) + cost[i];
            prevPrev = prev;
            prev = curr;
        }
        return min(prev, prevPrev);
    }
};
