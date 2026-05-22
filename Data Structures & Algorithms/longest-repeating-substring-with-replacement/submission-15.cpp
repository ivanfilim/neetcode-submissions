class Solution {
public:
    int characterReplacement(const string &s, const int k) {
        int result = 0;
        map<char, int> letters_freq;
        int left = 0;
        int max_frequency = 1;
        for (int right = 0; right < s.length(); ++right) {
            if (letters_freq.find(s[right]) == letters_freq.end()) {
                letters_freq[s[right]] = 1;
            } else {
                ++letters_freq[s[right]];
            }
            max_frequency = max(max_frequency, letters_freq[s[right]]);
            if (right - left + 1 - max_frequency > k) {
                --letters_freq[s[left]];
                ++left;
            }
            if (right - left + 1 > result) {
                result = right - left + 1;
            }
        }
        return result;
    }
};