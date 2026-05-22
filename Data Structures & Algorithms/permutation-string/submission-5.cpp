class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }
        map<char, int> s1Map;
        map<char, int> modifiableMap;
        for (int i = 0; i < 26; ++i) {
            s1Map['a' + i] = 0;
            modifiableMap['a' + i] = 0;
        }        
        for (int i = 0; i < s1.length(); ++i) {
            ++s1Map[s1[i]];
            ++modifiableMap[s2[i]];
        }
        int matches = 26;
        for (int i = 0; i < 26; ++i) {
            if (s1Map['a' + i] != modifiableMap['a' + i]) {
                --matches;
            }
        }
        int l = 0;
        for (int r = s1.length(); r < s2.length(); ++r) {
            if (matches == 26) {
                return true;
            }
            ++modifiableMap[s2[r]];
            if (modifiableMap[s2[r]] == s1Map[s2[r]]) {
                ++matches;
            } else if (modifiableMap[s2[r]] == s1Map[s2[r]] + 1) {
                --matches;
            }
            --modifiableMap[s2[l]];
            if (modifiableMap[s2[l]] == s1Map[s2[l]]) {
                ++matches;
            } else if (modifiableMap[s2[l]] == s1Map[s2[l]] - 1) {
                --matches;
            }
            ++l;
        }
        return matches == 26;
    }
};
