class Solution {
public:
    int rob(vector<int>& nums) {
        auto house = vector<int>(nums.size());
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        house[0] = nums[0];
        house[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            house[i] = max(house[i - 2] + nums[i], house[i - 1]);
        }
        return house[nums.size() - 1];
    }
};
