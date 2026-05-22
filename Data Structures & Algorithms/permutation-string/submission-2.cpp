class Solution {
    map<char, int> generateMap(const string& s) {
        map<char, int> result;
        for (char c : s) {
            if (result.find(c) == result.end()) {
                result[c] = 1;
            } else {
                ++result[c];
            }
        }
        return result;
    }
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> s1Map = generateMap(s1);
        map<char, int> modifiableMap = generateMap(s2.substr(0, s1.length()));
        int l = 0;
        for (int r = s1.length() - 1; r < s2.length(); ++r) {
            if (s1Map == modifiableMap) {
                return true;
            } else if (r != s2.length() - 1) {
                --modifiableMap[s2[l]];
                if (modifiableMap[s2[l]] == 0) {
                    modifiableMap.erase(s2[l]);
                }
                ++l;
                if (modifiableMap.find(s2[r + 1]) == modifiableMap.end()) {
                    modifiableMap[s2[r + 1]] = 1;
                } else {
                    ++modifiableMap[s2[r + 1]];
                }
            }
        }
        return false;
    }
};
