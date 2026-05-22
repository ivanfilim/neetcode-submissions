class Solution {
public:
    int carFleet(const int target, vector<int>& position, const vector<int>& speed) {
        map<int, int> m;
        for (int i = 0; i < position.size(); ++i) {
            if (m.find(position[i]) == m.end() || m[position[i]] > speed[i]) {
                m[position[i]] = speed[i];
            }
        }
        sort(position.begin(), position.end());
        stack<double> s;
        for (int i = position.size() - 1; i >= 0; --i) {
            double curr_time = (target - position[i]) / static_cast<double>(m[position[i]]);
            if (s.empty() || s.top() < curr_time) {
                s.push(curr_time);
            }
        }
        return s.size();
    }
};