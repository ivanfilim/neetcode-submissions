class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        complements = {}
        for i in range(len(nums)):
            complements[target - nums[i]] = i
        for i in range(len(nums)):
            if nums[i] in complements and i != complements[nums[i]]:
                return [i, complements[nums[i]]]