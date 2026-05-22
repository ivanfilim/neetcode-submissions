class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        
        int n = nums.size(); 
        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0] = 1;
        suffix[n - 1] = 1;
        for (int i = 1; i < n - 1; ++i) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
            suffix[n - 1 - i] = suffix[n - i] * nums[n - i];
        }
        prefix[n - 1] = prefix[n - 2] * nums[n - 2];
        suffix[0] = suffix[1] * nums[1];

        for (int i = 0; i < n; ++i) {
            output.push_back(prefix[i] * suffix[i]);
        }

        return output;
    }
};
