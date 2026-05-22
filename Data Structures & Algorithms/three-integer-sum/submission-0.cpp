class Solution {
    vector<vector<int>> twoSum(const vector<int>& nums_sorted, int target) {
        vector<vector<int>> result;
        int left = 0, right = nums_sorted.size() - 1;
        while (left < right) {
            int curr_sum = nums_sorted[left] + nums_sorted[right];
            if (curr_sum == target ) {
                vector pair = { nums_sorted[left], nums_sorted[right] };
                if (find(result.begin(), result.end(), pair) == result.end()) {
                    result.push_back(pair);
                }
                --right;
                ++left;
            } else if (curr_sum < target) {
                ++left;
            } else {
                --right;
            }
        }
        return result;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            vector sub_vector(nums.begin() + i + 1, nums.end());
            vector<vector<int>> triples = twoSum(sub_vector, -nums[i]);
            for (vector triple : triples) {
                triple.push_back(nums[i]);
                result.push_back(triple);
            }
        }
        return result;
    }
};
