class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result(nums.size() - k + 1);

        map<int, int> frequencies;
        set<int, greater<int>> unique_nums_sorted;
        for (int i = 0; i < k; ++i) {
            if (frequencies.find(nums[i]) == frequencies.end()) {
                frequencies[nums[i]] = 1;
                unique_nums_sorted.insert(nums[i]);
            } else {
                ++frequencies[nums[i]];
            }
        }

        result[0] = *unique_nums_sorted.begin();
        for (int l = 1; l <= nums.size() - k; ++l) {
            int r = l + k - 1;
            if (--frequencies[nums[l - 1]] == 0) {
                frequencies.erase(nums[l - 1]);
                unique_nums_sorted.erase(nums[l - 1]);
            }
            if (frequencies.find(nums[r]) == frequencies.end()) {
                frequencies[nums[r]] = 1;
                unique_nums_sorted.insert(nums[r]);
            } else {
                ++frequencies[nums[r]];
            }
            result[l] = *unique_nums_sorted.begin();
        }

        return result;
    }
};
