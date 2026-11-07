class Solution {
    public int search(int[] nums, int target) {
        int l = 0, r = nums.length - 1;
        while (true) {
            int i = l + (r - l) / 2;
            if (nums[i] < nums[l])
                r = i;
            else if (nums[i] > nums[r])
                l = i + 1;
            else
                break;
        }
        int minIdx = l;
        if (target < nums[minIdx])
            return -1;
        else if (target <= nums[nums.length - 1])
            r = nums.length - 1;
        else if (minIdx > 0) {
            l = 0;
            r = minIdx;
        } else 
            return -1;
        while (l <= r) {
            int i = l + (r - l) / 2;
            if (nums[i] > target)
                r = i - 1;
            else if (nums[i] < target)
                l = i + 1;
            else
                return i;
        }
        return -1;
    }
}
