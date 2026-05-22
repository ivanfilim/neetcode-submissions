class Solution {
    int sumOfSquares(int n) {
        int result = 0;
        do {
            result += static_cast<int>(pow(n % 10, 2));
            n /= 10;
        } while (n > 0);
        return result;
    }
public:
    bool isHappy(int n) {
        pmr::set<int> producedNumbers;
        while (true) {
            n = sumOfSquares(n);
            if (n == 1) {
                return true;
            }
            if (producedNumbers.find(n) != producedNumbers.end()) {
                return false;
            }
            producedNumbers.insert(n);
        }
    }
};
