class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = static_cast<int>(nums.size());
        for (int i = 0; i <= static_cast<int>(nums.size()) - 1; ++i) {
            res ^= (i ^ nums[i]);
        }
        return res;
    }
};
