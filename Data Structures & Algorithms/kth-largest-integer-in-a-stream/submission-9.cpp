class KthLargest {
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    KthLargest(int k, vector<int>& nums) : k(k), minHeap(nums.begin(), nums.end()) {}

    int add(int val) {
        minHeap.push(val);
        while (minHeap.size() > k) minHeap.pop();
        return minHeap.top();
    }
};
