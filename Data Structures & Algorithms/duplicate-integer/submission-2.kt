class Solution {
    fun hasDuplicate(nums: IntArray): Boolean {
        val s = mutableSetOf<Int>()
        nums.forEach { num ->
            if (s.contains(num)) {
                return true
            }
            s.add(num)
        }
        return false
    }
}
