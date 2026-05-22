class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t twoPow = static_cast<uint32_t>(pow(2, 31));
        uint32_t result = 0;
        for (int i = 1; i <= 32; ++i) {
            result += (n % 2) * twoPow;
            n /= 2;
            twoPow /= 2;
        }
        return result;
    }
};
