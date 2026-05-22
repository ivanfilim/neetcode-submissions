class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result(nums.size() - k + 1);
        deque<int> indices;
        int l = 0, r = 0;
        while (r < nums.size()) {
            // pop smaller values from deque
            while (!indices.empty() && nums[indices.back()] < nums[r]) {
                indices.pop_back();
            }
            indices.push_back(r);
            //remove left value from window
            if (l > indices.front()) {
                indices.pop_front();
            }
            if (r + 1 >= k) {
                result[l] = nums[indices.front()];
                ++l;
            }
            ++r;
        }
        return result;
    }
};
