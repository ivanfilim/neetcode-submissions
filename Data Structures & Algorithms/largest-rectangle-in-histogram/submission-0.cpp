class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        map<int, int> left;
        map<int, int> right;
        for (int i = 0; i < heights.size(); ++i) {
            int l = i, r = i;
            while (l - 1 >= 0 && heights[l - 1] >= heights[i]) {
                --l;
            }
            left[i] = l;
            while (r + 1 < heights.size() && heights[r + 1] >= heights[i]) {
                ++r;
            }
            right[i] = r;
        }
        int res = heights[0];
        for (int i = 0; i < heights.size(); ++i) {
            int curr_area = (right[i] - left[i] + 1) * heights[i];
            res = max(curr_area, res);
        }
        return res;
    }
};
