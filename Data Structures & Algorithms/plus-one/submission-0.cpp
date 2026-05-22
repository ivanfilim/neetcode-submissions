class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> newDigits;
        int idx = static_cast<int>(digits.size()) - 1;
        while (idx >= 0 && digits[idx] == 9) {
            newDigits.insert(newDigits.begin(), 0);
            --idx;
        }
        if (idx < 0) {
            newDigits.insert(newDigits.begin(), 1);
        } else {
            newDigits.insert(newDigits.begin(), digits[idx] + 1);
            --idx;
            while (idx >= 0) {
                newDigits.insert(newDigits.begin(), digits[idx]);
                --idx;
            }
        }
        return newDigits;
    }
};
