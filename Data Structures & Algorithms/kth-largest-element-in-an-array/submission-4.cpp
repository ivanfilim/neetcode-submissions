class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap;
        for (int n: nums) {
            heap.push(n);
        }
        int res;
        for (int i = 0; i < k; ++i) {
            res = heap.top();
            heap.pop();
        }
        return res;
    }
};
