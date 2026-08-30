class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> heap;
        for (const auto& point : points) {
            int distance = point[0] * point[0] + point[1] * point[1];
            heap.push(pair<int, vector<int>>(distance, point));
            if (heap.size() > k) heap.pop();
        }
        vector<vector<int>> res;
        while (!heap.empty()) {
            vector<int> point = heap.top().second;
            res.push_back(point);
            heap.pop();
        }
        return res;
    }
};
