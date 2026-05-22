class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int idx = static_cast<int>(digits.size()) - 1;
        while (idx >= 0) {
            if (digits[idx] < 9) {
                ++digits[idx];
                return digits;
            }
            digits[idx] = 0;
            --idx;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
