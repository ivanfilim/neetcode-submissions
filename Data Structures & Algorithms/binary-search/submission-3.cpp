class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int idx = (l + r) / 2;
            if (nums[idx] > target) {
                r = idx - 1;
            } else if (nums[idx] < target) {
                l = idx + 1;
            } else {
                return idx;
            }
        }
        return -1;
    }
};
