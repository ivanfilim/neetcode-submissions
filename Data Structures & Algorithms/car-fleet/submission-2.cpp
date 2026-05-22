class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, int> m;
        for (int i = 0; i < position.size(); ++i) {
            if (m.find(position[i]) == m.end() || m[position[i]] > speed[i]) {
                m[position[i]] = speed[i];
            }
        }
        sort(position.begin(), position.end());
        stack<double> s;        
        for (int i = position.size() - 1; i >= 0; --i) {
            double time_to_reach_target = (target - position[i]) / static_cast<double>(m[position[i]]);
            if (s.empty() || time_to_reach_target > s.top()) {
                s.push(time_to_reach_target);
            }
        }
        return s.size();
    }
};
