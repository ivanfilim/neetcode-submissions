class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev = *(cost.end() - 1);
        int prevPrev = *(cost.end() - 2);
        for (int i = 3; i <= cost.size(); ++i) {
            int currCost = *(cost.end() - i);
            int newPrev = prevPrev;
            prevPrev = currCost + min(prev, prevPrev);
            prev = newPrev;
        }
        return min(prev, prevPrev);
    }
};
