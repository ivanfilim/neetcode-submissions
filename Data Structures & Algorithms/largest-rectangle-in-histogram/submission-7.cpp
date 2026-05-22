class Solution {
public:
    int largestRectangleArea(const vector<int>& heights) {
        int res = heights[0];
        stack<pair<int, int>> s; // idx to height
        for (int i = 0; i <= heights.size(); ++i) {
            int start = i;
            while (!s.empty() && 
                   (i == heights.size() || s.top().second > heights[i])) {
                res = max(res, (i - s.top().first) * s.top().second);
                start = s.top().first;
                s.pop();
            }
            if (i == heights.size()) {
                break;
            }
            s.push(pair(start, heights[i]));
        }        
        return res;
    }
};
