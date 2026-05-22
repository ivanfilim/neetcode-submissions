class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        int max_frequency = 1;
        for (int n : nums) {
            if (m.find(n) == m.end()) {
                m[n] = 1;
            } else {
                ++m[n];
                if (m[n] > max_frequency) {
                    max_frequency = m[n];
                }
            }
        }
        map<int, vector<int>> frequencies_to_nums;
        for (const auto& [num, frequency] : m) {
            if (frequencies_to_nums.find(frequency) == frequencies_to_nums.end()) {
                frequencies_to_nums[frequency] = { num };
            } else {
                frequencies_to_nums[frequency].push_back(num);
            }
        }
        vector<int> result;
        int curr_frequency = max_frequency;
        while (result.size() != k) {
            if (frequencies_to_nums.find(curr_frequency) == frequencies_to_nums.end()) {
                --curr_frequency;
                continue;
            }
            vector<int> curr_nums = frequencies_to_nums[curr_frequency];
            if (result.size() + curr_nums.size() > k) {
                int size_we_want = k - result.size();
                curr_nums = vector<int> (curr_nums.begin(), curr_nums.begin() + size_we_want);
            }
            result.insert(result.end(), curr_nums.begin(), curr_nums.end());
            --curr_frequency;
        }
        return result;
    }
};
