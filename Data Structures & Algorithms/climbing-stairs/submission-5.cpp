class Solution {
public:
    int climbStairs(int n) {
        int res, prev;
        for (int i = 1; i<=n;++i) {
            if (i==1) res = 1;
            else if (i==2) {
                res = 2;
                prev=1;
            } else {
                res += prev;
                prev=res-prev;
            }
        }
        return res;
    }
};
