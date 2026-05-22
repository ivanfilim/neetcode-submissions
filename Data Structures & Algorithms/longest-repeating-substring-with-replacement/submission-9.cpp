class Solution {
public:
    int characterReplacement(string s, int k) {
        int result = 1;
        for (int l = 0; l < s.length(); ++l) {
            int left = l;
            int right = left;
            int replacements_left = k;
            char curr_char = s[l];
            while (right + 1 < s.length() && (s[right + 1] == curr_char || replacements_left > 0)) {
                if (s[right + 1] != curr_char) {
                    --replacements_left;
                }
                ++right;
            }
            left = max(0, l - replacements_left);
            result = max(result, right - left + 1);
        }
        return result;
    }
};
