class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, const int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            m[target - nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(nums[i]) != m.end() && m[nums[i]] != i) {
                return (m[nums[i]] < i) ? vector{m[nums[i]], i} : vector{i, m[nums[i]]};
            }
        }
        throw runtime_error("Not found");
    }
};