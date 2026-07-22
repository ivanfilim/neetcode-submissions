class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        curr = 1
        p = [curr]
        for i in range(0, len(nums) - 1):
            curr *= nums[i]
            p.append(curr)
        curr = 1
        s = [curr]
        for i in range(len(nums) - 1, 0, -1):
            curr *= nums[i]
            s = [curr] + s
        res = []
        for i in range(len(nums)):
            res.append(p[i] * s[i])
        return res
