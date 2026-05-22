class Solution {
    int biggestFrequency(const map<char, int> &m) {
        return max_element(
            m.begin(),
            m.end(),
            [](const auto &a, const auto &b) { return a.second < b.second; }
        )->second;
    }
    int substringLength(const int left, const int right) {
        return right - left + 1;
    }
public:
    int characterReplacement(const string &s, const int k) {
        int result = 0;
        
        int left = 0, right = 0;
        map<char, int> letters_freq;
        while (right < s.length()) {
            if (letters_freq.find(s[right]) == letters_freq.end()) {
                letters_freq[s[right]] = 1;
            } else {
                ++letters_freq[s[right]];
            }
            while (substringLength(left, right) - biggestFrequency(letters_freq) > k) {
                --letters_freq[s[left]];
                ++left;
            }
            if (substringLength(left, right) > result) {
                result = substringLength(left, right);
            }
            ++right;
        }

        return result;
    }
};