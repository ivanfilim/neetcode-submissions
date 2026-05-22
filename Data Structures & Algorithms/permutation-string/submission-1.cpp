class Solution {
    bool isPermutation(const string& s, map<char, int> m) {
        for (char c: s) {
            if (m.find(c) == m.end()) {
                return false;
            }
            --m[c];
        }
        for (const auto& [k, v] : m) {
            if (v != 0) return false;
        }
        return true;
    }
public:
    bool checkInclusion(const string& s1, const string &s2) {
        if (s1.length() > s2.length()) {
            return false;
        }
        map<char, int> chars_frequencies;
        int l = 0;
        for (int r = 0; r < s2.length(); ++r) {
            if (s1.find(s2[r]) == string::npos) {
                l = r + 1;
                chars_frequencies.clear();
                continue;
            }
            if (chars_frequencies.find(s2[r]) == chars_frequencies.end()) {
                chars_frequencies[s2[r]] = 1;
            } else {
                ++chars_frequencies[s2[r]];
            }
            if (r - l + 1 == s1.length()) {
                if (!isPermutation(s1, chars_frequencies)) {
                    --chars_frequencies[s2[l]];
                    ++l;
                }
                else return true;
            }
        }
        return false;
    }
};