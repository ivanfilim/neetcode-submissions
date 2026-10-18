class Solution {
    void checkPalindrome(
            int l,
            int r,
            const string& s,
            int& resL,
            int& resR) {
        while (l >= 0 && r < ssize(s) && s[l] == s[r]) {
            if (r - l > resR - resL) {
                resL = l;
                resR = r;
            }
            --l;
            ++r;
        }
    }
public:
    string longestPalindrome(string s) {
        int resL = 0, resR = 0;
        for (int i = 0; i < ssize(s); ++i) {
            checkPalindrome(i, i, s, resL, resR);
            checkPalindrome(i, i + 1, s, resL, resR);
        }
        return s.substr(resL, resR - resL + 1);
    }
};
