class Solution {
    public int findMin(int[] nums) {
        int l = 0, r = nums.length - 1;
        while (l <= r) {
            int i = l + (r - l) / 2;
            if (nums[i] < nums[l])
                r = i;
            else if (nums[i] > nums[r])
                l = i + 1;
            else 
                break;
        }
        return nums[l];
    }
}