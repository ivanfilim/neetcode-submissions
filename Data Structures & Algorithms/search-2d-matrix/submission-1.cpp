class Solution {
    int calculateIdx(const int& left, const int& right) {
        return left + (right - left) / 2;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m - 1;
        int i;
        while (l <= r) {
            i = calculateIdx(l, r);
            if (matrix[i][n - 1] < target) {
                l = i + 1;
            } else if (matrix[i][0] > target) {
                r = i - 1;
            } else {
                break;
            }
        }
        if (l > r) {
            return false;
        } else {
            int le = 0, ri = n - 1;
            while (le <= ri) {
                int idx = calculateIdx(le, ri);
                if (matrix[i][idx] < target) {
                    le = idx + 1;
                } else if (matrix[i][idx] > target) {
                    ri = idx - 1;
                } else {
                    return true;
                }
            }
            return false;
        }
    }
};
