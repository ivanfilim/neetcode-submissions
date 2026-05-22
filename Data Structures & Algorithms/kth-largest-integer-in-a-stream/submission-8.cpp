class KthLargest {
    int k;
    priority_queue<int, vector<int>, greater<>> minHeap;
public:
    KthLargest(const int k, const vector<int>& nums) {
        this->k = k;
        minHeap = priority_queue<int, vector<int>, greater<>>(
            nums.begin(), 
            nums.end()
        );
        for (int i = 0; i < static_cast<int>(nums.size() - k); ++i) {
            minHeap.pop();
        }
    }
    
    int add(const int val) {
        minHeap.push(val);
        while (minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};