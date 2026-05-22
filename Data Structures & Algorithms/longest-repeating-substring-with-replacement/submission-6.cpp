class Solution {
public:
    int characterReplacement(string s, int k) {
        int result = 1;
        for (int l = 0; l < s.length(); ++l) {
            int left = l;
            int chars_replaced = k;
            int r = l;
            char curr_char = s[l];
            while (r + 1 < s.length() && (s[r + 1] == curr_char || chars_replaced > 0)) {
                if (s[r + 1] != curr_char) {
                    --chars_replaced;
                }
                ++r;
            }
            left = max(0, l - chars_replaced);
            result = max(result, r - left + 1);
        }
        return result;
    }
};
