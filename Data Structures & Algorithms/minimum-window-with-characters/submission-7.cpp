class Solution {
    map<char, int> mapForString(string s) {
        map<char, int> m;
        for (char c: s) {
            if (m.find(c) == m.end()) {
                m[c] = 1;
            } else {
                ++m[c];
            }
        }
        return m;
    }
    void insertCharIntoMap(map<char, int>& m, char c) {
        if (m.find(c) == m.end()) {
            m[c] = 1;
        } else {
            ++m[c];
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
        map<char, int> target_map = mapForString(t);
        map<char, int> curr_map;
        for (int i = 0; i < t.length() - 1; ++i) {
            if (t.find(s[l + i]) == string::npos) {
                continue;
            }
            insertCharIntoMap(curr_map, s[l + i]);
        }
        const unsigned long target_matches_count = target_map.size();
        int matches_count = 0;
        for (const auto& [k, v]: target_map) {
            if (curr_map.find(k) == curr_map.end() || curr_map[k] < target_map[k]) {
                continue;
            }
            ++matches_count;
        }
        for (int r = l + t.length() - 1; r < s.length(); ++r) {
            if (t.find(s[r]) == string::npos) {
                continue;
            }
            insertCharIntoMap(curr_map, s[r]);
            if (curr_map[s[r]] == target_map[s[r]]) {
                ++matches_count;
            }
            if (matches_count != target_matches_count) {
                continue;
            }
            while (true) {
                if (t.find(s[l]) != string::npos && curr_map[s[l]] == target_map[s[l]]) {
                    break;
                }
                if (t.find(s[l]) != string::npos) {
                    --curr_map[s[l]];
                }
                ++l;
            }
            if (result == "" || r - l + 1 < result.length()) {
                result = s.substr(l, r - l + 1);
            }
            --matches_count;
            --curr_map[s[l]];
            ++l;
        }
        return result;
    }
};