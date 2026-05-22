class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        set<int> unique_chars;
        int l = 0;
        for (int r = 0; r < s.length(); ++r) {
            while (unique_chars.find(s[r]) != unique_chars.end()) {
                unique_chars.erase(s[l]);
                ++l;
            }
            unique_chars.insert(s[r]);
            result = max(result, (int) unique_chars.size());
        }
        return result;    
    }
};
