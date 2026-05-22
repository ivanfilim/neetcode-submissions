class Solution {
public:
    int search(const vector<int>& nums, int target) {
        int l = 0;
        int r = static_cast<int>(nums.size()) - 1;
        while (l <= r) {
            int idx = l + (r - l) / 2;
            if (nums[idx] < target) {
                if (nums[idx] > nums[r] || nums[r] >= target) {
                    l = idx + 1;    
                } else {
                    r = idx - 1;
                }
            } else if (nums[idx] > target) {
                if (nums[idx] < nums[l] || nums[l] <= target) {
                    r = idx - 1;    
                } else {
                    l = idx + 1;
                }
            } else {
                return idx;
            }
        }        
        return -1;
    }
};
