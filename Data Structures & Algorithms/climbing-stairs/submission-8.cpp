class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int prevPrev = 1, prev = 2, curr;
        for (int i = 3; i <= n; ++i) {
            curr = prev + prevPrev;
            prevPrev = prev;
            prev = curr;
        }
        return curr;
    }
};
