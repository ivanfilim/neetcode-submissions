class Solution {
public:
    int characterReplacement(string s, int k) {
        int result = 1;
        for (int l = 0; l < s.length(); ++l) {
            int left = l;
            int replacements_left = k;
            int r = l;
            char curr_char = s[l];
            while (r + 1 < s.length() && (s[r + 1] == curr_char || replacements_left > 0)) {
                if (s[r + 1] != curr_char) {
                    --replacements_left;
                }
                ++r;
            }
            left = max(0, l - replacements_left);
            result = max(result, r - left + 1);
        }
        return result;
    }
};
