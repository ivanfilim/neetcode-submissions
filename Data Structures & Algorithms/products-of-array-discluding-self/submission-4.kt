class Solution {
    fun productExceptSelf(nums: IntArray): IntArray {
        val res = IntArray(nums.size)

        val prefixMult = IntArray(nums.size)
        val suffixMult = IntArray(nums.size)

        for (i in 0..nums.size-1) {
            if (i == 0) {
                prefixMult[i] = 1
                suffixMult[nums.size - 1] = 1
            } else {
                prefixMult[i] = prefixMult[i - 1] * nums[i -1]
                suffixMult[nums.size - 1 - i] = suffixMult[nums.size - i] * nums[nums.size - i]
            }
        }

        for (i in 0..nums.size-1) {
            res[i] = prefixMult[i] * suffixMult[i]
        }

        return res
    }
}
