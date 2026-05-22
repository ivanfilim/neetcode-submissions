class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = heights[0];
        stack<int> s;
        for (int i = 0; i < heights.size(); ++i) {
            int last_poped = -1;
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int area = (i - s.top()) * heights[s.top()];
                res = max(res, area);
                last_poped = s.top();
                s.pop();
            }
            if (last_poped != -1) {
                heights[last_poped] = heights[i];
                s.push(last_poped);
            }
            s.push(i);
        }    
        while (!s.empty()) {
            int area = (heights.size() - s.top()) * heights[s.top()];
            res = max(res, area);
            s.pop();
        }    
        return res;
    }
};
