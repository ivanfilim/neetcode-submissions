class Solution {
public:
    int trap(const vector<int>& height) {
        int result = 0;

        vector<int> left_heights(height.size());
        vector<int> right_heights(height.size());

        int max_prefix = height[0];
        for (int i = 0; i < height.size(); ++i) {
            left_heights[i] = max_prefix;
            if (height[i] > max_prefix) {
                max_prefix = height[i];
            }
        }

        int max_suffix = height[height.size() - 1];
        for (int i = height.size() - 1; i >= 0; --i) {
            right_heights[i] = max_suffix;
            if (height[i] > max_suffix) {
                max_suffix = height[i];
            }
        }

        for (int i = 0; i < height.size(); ++i) {
            if (left_heights[i] > height[i] && right_heights[i] > height[i]) {
                result += min(left_heights[i], right_heights[i]) - height[i];
            }
        }
        return result;
    }
};