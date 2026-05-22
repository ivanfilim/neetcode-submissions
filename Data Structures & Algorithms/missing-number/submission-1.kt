class Solution {
    fun missingNumber(nums: IntArray): Int {
        var res = 0
        var sum = 0
        nums.forEach {
            res = res.xor(it)
        }
        (0..nums.size).forEach {
            sum=sum.xor(it)
        }
        return sum.xor(res)
    }
}
