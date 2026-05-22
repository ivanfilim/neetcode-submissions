class TimeMap {
    map<string, vector<pair<int, string>>> m;
public:
    TimeMap() : m() {}
    
    void set(string key, string value, int timestamp) {
        pair<int, string> p(timestamp, value);
        if (m.find(key) == m.end()) {
            m[key] = vector<pair<int, string>>();
        }
        m[key].push_back(p);
    }
    
    string get(string key, int timestamp) {
        if (m.find(key) == m.end() || m[key][0].first > timestamp) {
            return "";
        }
        int l = 0;
        int r = static_cast<int>(m[key].size() - 1);
        int res = l;
        while (l <= r) {
            int idx = l + (r - l) / 2;
            if (m[key][idx].first <= timestamp) {
                res = idx;
                l = idx + 1;
            } else {
                r = idx - 1;
            }
        }
        return m[key][res].second;
    }
};
