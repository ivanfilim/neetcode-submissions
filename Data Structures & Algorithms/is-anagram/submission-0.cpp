class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        map<char, int> map_s, map_t;
        for (char c : s) {
            if (map_s.find(c) == map_s.end()) {
                map_s[c] = 1;
            } else {
                ++map_s[c];
            }
        }
        for (char c : t) {
            if (map_t.find(c) == map_t.end()) {
                map_t[c] = 1;
            } else {
                ++map_t[c];
            }
        }
        return map_s == map_t;
    }
};