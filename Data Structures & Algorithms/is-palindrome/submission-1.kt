class Solution {
    fun isPalindrome(s: String): Boolean {
        var l = 0
        var r = s.length - 1
        while (l <= r) {
            if (!s[l].isLetterOrDigit()) {
                l++
                continue
            }
            if (!s[r].isLetterOrDigit()) {
                r--
                continue
            }
            if (!s[l].equals(s[r], true)) {
                return false
            }
            l++
            r--
        }
        return true
    }
}
