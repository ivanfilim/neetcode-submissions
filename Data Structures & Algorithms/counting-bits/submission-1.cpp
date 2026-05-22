class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1);
        int offset = 2;
        for (int i = 0; i <= n; ++i) {
            if (i == 0) {
                result[i] = 0;
            } else if (i == 1) {
                result[i] = 1;
            } else {
                offset = (i == 2 * offset) ? i : offset;
                result[i] = 1 + result[i - offset];
            }
        }
        return result;
    }
};
