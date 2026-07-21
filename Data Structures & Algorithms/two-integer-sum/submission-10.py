class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        complements = {}
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement not in complements:
                complements[complement] = i
            if (nums[i] in complements and i != complements[nums[i]]):
                return [complements[nums[i]], i]