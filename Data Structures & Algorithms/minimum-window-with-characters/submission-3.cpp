class Solution {
    map<char, int> mapForString(const string& s) {
        map<char, int> m;
        for (int i = 0; i < s.length(); ++i) {
            if (m.find(s[i]) == m.end()) {
                m[s[i]] = 1;
            } else {
                ++m[s[i]];
            }
        }
        return m;
    }
    bool isMatch(map<char, int> targetMap, map<char, int> otherMap) {
        for (const auto& [k, v]: targetMap) {
            if (otherMap.find(k) == otherMap.end() || otherMap[k] < targetMap[k]) {
                return false;
            }
        }
        return true;
    }
    void reduceCharInMap(map<char, int>& m, char c) {
        if (m.find(c) == m.end()) {
            return;
        }
        --m[c];
        if (m[c] == 0) {
            m.erase(c);
        }
    }
public:
    string minWindow(string s, string t) {
        string result = "";
        int l = 0;
        while (l < s.length() && t.find(s[l]) == string::npos) {
            ++l;
        }
        if (s.length() - l < t.length()) {
            return result;
        }
        map<char, int> tMap = mapForString(t);
        map<char, int> curr_map = mapForString(s.substr(l, t.length()));
        for (int r = l + t.length() - 1; r < s.length(); ++r) {
            curr_map = mapForString(s.substr(l, r - l + 1));
            if (!isMatch(tMap, curr_map)) {
                continue;
            }
            while (true) {
                char prev_key = s[l];
                int prev_value = curr_map[s[l]];
                reduceCharInMap(curr_map, s[l]);
                if (isMatch(tMap, curr_map)) {
                    ++l;
                } else {
                    curr_map[prev_key] = prev_value;
                    break;
                }
            }
            if (result == "" || result.length() > r - l + 1) {
                result = s.substr(l, r - l + 1);
            }
            reduceCharInMap(curr_map, s[l]);
            ++l;
        }
        return result;
    }
};