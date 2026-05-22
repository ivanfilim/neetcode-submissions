class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = nums[0];
        for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
            result ^= nums[i];
        }
        return result;
    }
};
