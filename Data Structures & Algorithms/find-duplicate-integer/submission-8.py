class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        slow, fast = 0, 0
        while True:
            slow, fast = nums[slow], nums[nums[fast]]
            if slow == fast:
                break
        newSlow = 0
        while slow != newSlow:
            slow = nums[slow]
            newSlow = nums[newSlow]
        return slow