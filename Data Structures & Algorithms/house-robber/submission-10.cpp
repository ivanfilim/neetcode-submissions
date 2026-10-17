class Solution {
public:
    int rob(vector<int>& nums) {
        if (ssize(nums) == 1) return nums[0];
        if (ssize(nums) == 2) return max(nums[0], nums[1]);
        int prev = max(nums[0], nums[1]);
        int prevPrev = nums[0];
        int curr = prev;
        for (int i = 2; i < ssize(nums); ++i) {
            curr = max(prevPrev + nums[i], prev);
            prevPrev = prev;
            prev = curr;
        }
        return curr;
    }
};
