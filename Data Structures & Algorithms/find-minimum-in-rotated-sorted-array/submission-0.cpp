class Solution {
public:
    int findMin(const vector<int> &nums) {
        int l = 0;
        int r = static_cast<int>(nums.size()) - 1;
        int idx = 0;
        int res = nums[idx];         
        while (l <= r) {
            int idx = l + (r - l) / 2;
            if (nums[idx] > nums[r]) {
                l = idx + 1;
            } else {
                res = min(res, nums[idx]);
                r = idx - 1;
            }
        }
        return res;
    }
};
