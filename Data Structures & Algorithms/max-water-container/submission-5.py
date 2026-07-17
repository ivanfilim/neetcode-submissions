class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l, r = 0, len(heights) - 1
        result = (r - l) * min(heights[l], heights[r])
        while l < r:
            if heights[l] < heights[r]:
                l += 1
            else:
                r -= 1
            result = max(result, (r - l) * min(heights[l], heights[r]))        
        return result             

        