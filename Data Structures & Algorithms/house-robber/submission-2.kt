class Solution {
    fun rob(nums: IntArray): Int {
        var house = IntArray(nums.size);
        if (nums.size == 1) {
            return nums[0]
        }
        if (nums.size == 2) return max(nums[0], nums[1])
        house[0] = nums[0]
        house[1] = max(nums[0], nums[1])
        house[2] = max(nums[0] + nums[2], nums[1])
        for (i in 3..nums.size-1) {
            house[i] = listOf(house[i-2] + nums[i], house[i-1]).max()
        }
        return house[nums.size - 1]
    }
}