class Solution {
public:
    int largestRectangleArea(const vector<int>& heights) {
        int res = heights[0];
        stack<pair<int, int>> s; // idx to height
        for (int i = 0; i <= heights.size(); ++i) {
            int last_popped = -1;
            while (!s.empty() && 
                   (i == heights.size() || s.top().second > heights[i])) {
                res = max(res, (i - s.top().first) * s.top().second);
                last_popped = s.top().first;
                s.pop();
            }
            if (last_popped != -1) {
                s.push(pair(last_popped, heights[i]));
            } else {
                s.push(pair(i, heights[i]));
            }
        }        
        return res;
    }
};
