class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int result;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) {
                result = abs(nums[i]);
                break;
            }
            nums[idx] *= -1;
        }
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            nums[i] = abs(nums[i]);
        }
        return result;
    }
};
