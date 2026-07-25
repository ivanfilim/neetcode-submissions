class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        starts = set()
        numsSet = set(nums)
        for n in nums:
            if n - 1 not in numsSet:
                starts.add(n)
        res = 0
        for s in starts:
            l = 1
            curr = s
            while curr + 1 in nums:
                l += 1
                curr += 1
            res = max(res, l)
        return res