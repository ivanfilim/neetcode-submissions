class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> nums_to_freq;
        for (int n : nums) {
            if (nums_to_freq.find(n) == nums_to_freq.end()) {
                nums_to_freq[n] = 1;
            } else {
                ++nums_to_freq[n];
            }
        }
        map<int, vector<int>> freq_to_nums;
        for (const auto& [num, freq] : nums_to_freq) {
            if (freq_to_nums.find(freq) == freq_to_nums.end()) {
                freq_to_nums[freq] = { num };
            } else {
                freq_to_nums[freq].push_back(num);
            }
        }
        vector<int> result;
        for (int i = nums.size(); i > 0; --i) {
            if (freq_to_nums.find(i) == freq_to_nums.end()) {
                continue;
            }
            for (int n : freq_to_nums[i]) {
                result.push_back(n);
                if (result.size() == k) {
                    return result;
                }
            }
        }
        return result;
    }
};
