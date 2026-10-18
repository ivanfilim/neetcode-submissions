class Solution {
    int rob(const vector<int>& nums, int l, int r) {
        if (l == r)
            return nums[l];
        if (l + 1 == r)
            return max(nums[l], nums[l + 1]);
        int prevPrev = nums[l];
        int prev = max(nums[l], nums[l + 1]);
        for (int i = l + 2; i <= r; ++i) {
            int curr = max(prev, prevPrev + nums[i]);
            prevPrev = prev;
            prev = curr;
        }
        return prev;
    }
public:
    int rob(const vector<int>& nums) {
        if (ssize(nums) == 1)
            return nums[0];
        return max(
            rob(nums, 0, ssize(nums) - 2),
            rob(nums, 1, ssize(nums) - 1)
        );
    }
};
