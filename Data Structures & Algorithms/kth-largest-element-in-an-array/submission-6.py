class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        idx = len(nums) - k

        def quickSelect(l, r):
            pivot, p = nums[r], l
            for i in range(l, r):
                if nums[i] <= pivot:
                    nums[p], nums[i] = nums[i], nums[p]
                    p += 1
            nums[p], nums[r] = nums[r], nums[p]
            if p > idx: 
                return quickSelect(l, p - 1)
            if idx > p:
                return quickSelect(p + 1, r)
            return nums[p]

        return quickSelect(0, len(nums) - 1)