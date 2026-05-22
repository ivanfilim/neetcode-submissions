class Solution {
    int climbStairs(int n, vector<int>& arr) {
        if (arr[n - 1] == 0) {
            arr[n - 1] = climbStairs(n - 1, arr) + climbStairs(n - 2, arr);
        }
        return arr[n - 1];
    }
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        vector<int> arr(n);
        arr[0] = 1;
        arr[1] = 2;
        return climbStairs(n, arr);
    }
};
