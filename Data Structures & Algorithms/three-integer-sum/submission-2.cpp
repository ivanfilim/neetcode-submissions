class Solution {
    vector<vector<int>> triplesForTarget(const vector<int>& nums_sorted, int target) {
        vector<vector<int>> result;
        int left = 0, right = nums_sorted.size() - 1;
        while (left < right) {
            int curr_sum = nums_sorted[left] + nums_sorted[right];
            if (curr_sum == -target) {
                result.push_back({ nums_sorted[left], nums_sorted[right], target });
                do
                    --right;
                while (right > 0 && nums_sorted[right] == nums_sorted[right + 1]);
                do
                    ++left;
                while (left < 0 && nums_sorted[left] == nums_sorted[left - 1]);
            } else if (curr_sum < -target) {
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
            vector<vector<int>> triples = triplesForTarget(sub_vector, nums[i]);
            result.insert(result.end(), triples.begin(), triples.end());
        }
        return result;
    }
};
