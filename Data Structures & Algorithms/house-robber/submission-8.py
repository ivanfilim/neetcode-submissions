class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        if len(nums) == 2:
            return max(nums[0], nums[1])
        prev, prevPrev = max(nums[0], nums[1]), nums[0]
        curr = prev
        for i in range(2, len(nums)):
            curr = max(prev, prevPrev + nums[i])
            prevPrev = prev
            prev = curr
        return curr