class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        val map = mutableMapOf<Int, Int>()
        nums.forEachIndexed { i, num ->
            if (map.contains(target - num)) {
                return intArrayOf(map[target - num]!!, i)
            }
            map[num] = i;
        }
        throw Exception("Impossible!")
    }
}
