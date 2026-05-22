class Solution {
    bool isAlphanumeric(const char c) {
        return (c >= '0' && c <= '9') ||
               (c >= 'A' && c <= 'Z') ||
               (c >= 'a' && c <= 'z');
    }
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            while (left < s.size() - 1 && !isAlphanumeric(s[left])) {
                ++left;
            }
            while (right > 0 && !isAlphanumeric(s[right])) {
                --right;
            }
            if (left >= right) {
                return true;
            }
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            ++left;
            --right;
        }        
        return true;
    }
};
