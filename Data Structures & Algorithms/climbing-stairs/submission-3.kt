class Solution {
    val m = mutableMapOf<Int, Int>(1 to 1, 2 to 2)

    fun climbStairs(n: Int): Int {
        if (m[n] != null) return m[n]!!
        m[n - 1] = climbStairs(n-1)
        m[n - 2] = climbStairs(n-2)
        return m[n - 1]!! + m[n-2]!!
    }
}
