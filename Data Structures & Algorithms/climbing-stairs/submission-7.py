class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1: 
            return 1
        elif n == 2: 
            return 2
        prev, prevPrev = 2, 1
        for i in range(3, n + 1):
            curr = prev + prevPrev
            prevPrev = prev
            prev = curr
        return curr