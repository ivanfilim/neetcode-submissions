class Solution:
    def longestPalindrome(self, s: str) -> str:
        resL, resR = 0, 0
        def checkPalindrome(l: int, r: int):
            nonlocal resL, resR
            while l >= 0 and r < len(s) and s[l] == s[r]:
                if r - l > resR - resL:
                    resL, resR = l, r
                l -= 1
                r += 1
        for i in range(len(s)):
            checkPalindrome(i, i)
            checkPalindrome(i, i + 1)
        return s[resL : resR + 1]