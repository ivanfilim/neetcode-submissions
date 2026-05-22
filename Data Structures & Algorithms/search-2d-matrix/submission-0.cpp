class Solution {
    int calculateIdx(const int& left, const int& right) {
        return left + (right - left) / 2;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m - 1;
        while (l <= r) {
            int i = calculateIdx(l, r);
            if (matrix[i][0] > target) {
                r = i - 1;
            } else if (matrix[i][0] < target) {
                int left = 0, right = n - 1;
                while (left <= right) {
                    int idx = calculateIdx(left, right);
                    if (matrix[i][idx] > target) {
                        right = idx - 1;
                    } else if (matrix[i][idx] < target) {
                        left = idx + 1;
                    } else {
                        return true;
                    }
                }
                l = i + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
