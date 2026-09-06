class Solution {
    int quickSelect(vector<int>& nums, int idx, int l, int r) {
        int pivot = nums[r];
        int p = l;
        for (int i = l; i < r; ++i) {
            if (nums[i] <= pivot) {
                int temp = nums[p];
                nums[p] = nums[i];
                nums[i] = temp;
                ++p;
            }
        }
        int temp = nums[p];
        nums[p] = nums[r];
        nums[r] = temp;
        if (idx > p) return quickSelect(nums, idx, p + 1, r);
        else if (idx < p) return quickSelect(nums, idx, l, p - 1);
        return nums[p];
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int idx = nums.size() - k;
        return quickSelect(
            nums, 
            idx, 
            0, 
            nums.size() - 1
        );        
    }
};
