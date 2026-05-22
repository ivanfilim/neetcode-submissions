class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        string substring;
        set<char> unique_chars;
        for (int i = 0; i < s.size(); ++i) {
            while (unique_chars.find(s[i]) != unique_chars.end()) {
                unique_chars.erase(substring[0]);
                substring = substring.substr(1, substring.size() - 1);
            }
            substring += s[i];
            unique_chars.insert(s[i]);
            result = max(result, (int) unique_chars.size());
        }
        return result;
    }
};
