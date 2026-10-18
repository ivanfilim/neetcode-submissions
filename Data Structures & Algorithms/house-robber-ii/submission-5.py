class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]

        def robLine(left, right):
            if left == right:
                return nums[left]
            if left + 1 == right:
                return max(nums[left], nums[left + 1])
            prevPrev, prev = nums[left], max(nums[left], nums[left + 1])
            for i in range(left + 2, right + 1):
                curr = max(prev, prevPrev + nums[i])
                prevPrev, prev = prev, curr
            return prev
        
        return max(
            robLine(0, len(nums) - 2),
            robLine(1, len(nums) - 1)
        )