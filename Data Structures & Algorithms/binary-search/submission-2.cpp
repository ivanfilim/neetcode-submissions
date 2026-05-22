class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while ((r - l) / 2 != 0) {
            int idx = l + (r - l) / 2;
            if (nums[idx] > target) {
                r = idx;
            } else if (nums[idx] < target) {
                l = idx;
            } else {
                return idx;
            }
        }
        return (nums[l] == target) ? l : (nums[r] == target ? r : -1);
    }
};
