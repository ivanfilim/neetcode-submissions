class Solution:
    def rob(self, nums: List[int]) -> int:
        length = len(nums)
        if len(nums) == 1:
            return nums[0]

        def robLine(numsLine: List[int]):
            if len(numsLine) == 1:
                return numsLine[0]
            elif len(numsLine) == 2:
                return max(numsLine[0], numsLine[1])
            prevPrev, prev = numsLine[0], max(numsLine[0], numsLine[1])
            for i in range(2, len(numsLine)):
                curr = max(prev, prevPrev + numsLine[i])
                prevPrev, prev = prev, curr
            return prev
        
        return max(robLine(nums[:length - 1]), robLine(nums[1:]))