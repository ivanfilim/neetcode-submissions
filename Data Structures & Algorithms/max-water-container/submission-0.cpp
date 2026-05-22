class Solution {
public:
    int maxArea(vector<int>& heights) {
        int result = 0;
        int left = 0;
        int right = heights.size() - 1;
        int width = heights.size() - 1;
        while (left < right) {
            int curr_amount = min(heights[left], heights[right]) * width;
            result = max(result, curr_amount);
            if (heights[left] > heights[right]) {
                --right;
            } else {
                ++left;
            }
            --width;
        }        
        return result;
    }
};
