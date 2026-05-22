class Solution {
    double median(const vector<int>& numsSorted) {
        const int half = static_cast<int>(numsSorted.size()) / 2;
        return numsSorted.size() % 2 == 1 ? numsSorted[half] : static_cast<double>(numsSorted[half] + numsSorted[half - 1]) / 2;
    }
public:
    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
        const vector<int>& smaller_arr = nums1.size() < nums2.size() ? nums1 : nums2;
        const vector<int>& larger_arr = nums1.size() < nums2.size() ? nums2 : nums1;

        if (smaller_arr.size() == 0) {
            return median(larger_arr);
        }

        const int total_size = static_cast<int>(smaller_arr.size() + larger_arr.size());
        const int half = total_size / 2;

        int l = 0, r = static_cast<int>(smaller_arr.size() - 1);
        while (true) {
            bool condition_for_smaller = true;
            bool condition_for_larger = true;

            const int smaller_arr_idx = l + (r - l) / 2;
            const int larger_arr_idx = half - smaller_arr_idx - 2;

            if (smaller_arr_idx + 1 == half) {
                condition_for_smaller = smaller_arr[smaller_arr_idx] <= larger_arr[0];
            } else {
                if (larger_arr_idx + 1 < larger_arr.size() && smaller_arr_idx >= 0 && smaller_arr_idx < smaller_arr.size()) {
                    condition_for_smaller = smaller_arr[smaller_arr_idx] <= larger_arr[larger_arr_idx + 1];
                }
                if (smaller_arr_idx + 1 < smaller_arr.size() && larger_arr_idx >= 0 && larger_arr_idx < larger_arr.size()) {
                    condition_for_larger = larger_arr[larger_arr_idx] <= smaller_arr[smaller_arr_idx + 1];
                }
            }

            if (condition_for_smaller && condition_for_larger) {
                    const int max_from_left = larger_arr_idx >= 0 ?
                                        max(smaller_arr[smaller_arr_idx], larger_arr[larger_arr_idx]) :
                                        smaller_arr[smaller_arr_idx];
                    int min_from_right;
                    if (smaller_arr_idx + 1 < smaller_arr.size() && larger_arr_idx + 1 < larger_arr.size()) {
                        min_from_right = min(smaller_arr[smaller_arr_idx + 1], larger_arr[larger_arr_idx + 1]);
                    } else if (smaller_arr_idx + 1 < smaller_arr.size()) {
                        min_from_right = smaller_arr[smaller_arr_idx + 1];
                    } else {
                        min_from_right = larger_arr[larger_arr_idx + 1];
                    }
                if (total_size % 2 == 0) {
                    return static_cast<double>(max_from_left + min_from_right) / 2;
                }
                return min_from_right;
            }
            if (!condition_for_smaller) {
                r = smaller_arr_idx - 1;
            } else {
                l = smaller_arr_idx + 1;
            }
            if (r < 0) {
                break;
            }
        }
        if (total_size % 2 == 1) {
            return min(larger_arr[half], smaller_arr[0]);
        }
        if (half < larger_arr.size()) {
            return static_cast<double>(min(larger_arr[half], smaller_arr[0]) + larger_arr[half - 1]) / 2;
        }
        return static_cast<double>(smaller_arr[0] + larger_arr[half - 1]) / 2;
    }
};