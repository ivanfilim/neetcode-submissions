class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        string substring;
        for (int i = 0; i < s.size(); ++i) {
            while (substring.find(s[i]) != string::npos) {
                substring = substring.substr(1, substring.size() - 1);
            }
            substring += s[i];
            result = max(result, (int) substring.size());
        }
        return result;
    }
};
