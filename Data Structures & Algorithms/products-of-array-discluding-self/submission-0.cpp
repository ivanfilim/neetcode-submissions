class Solution {
public:
    vector<int> productExceptSelf(const vector<int>& nums) {
        vector<int> output;
        vector<int> prefix;
        vector<int> suffix;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) {
                prefix.push_back(1);
            } else if (i == 1) {
                prefix.push_back(nums[0]);
            } else {
                prefix.push_back(prefix[i - 1] * nums[i - 1]);
            }
        }
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (i == nums.size() - 1) {
                suffix.push_back(1);
            } else if (i == nums.size() - 2) {
                suffix.push_back(nums[nums.size() - 1]);
            } else {
                suffix.push_back(suffix[nums.size() - i - 2] * nums[i + 1]);
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            output.push_back(prefix[i] * suffix[nums.size() - 1 - i]);
        }

        for (int i = 0; i < suffix.size(); ++i) {
            cout << suffix[i] << ' ';
        }
        cout << endl;

        return output;
    }
};