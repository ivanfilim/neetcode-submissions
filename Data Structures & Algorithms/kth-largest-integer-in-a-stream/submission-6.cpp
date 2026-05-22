class KthLargest {
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    KthLargest(int kk, vector<int>& nums) {
        k = kk;
        for (int n: nums) {
            minHeap.push(n);
        }
        for (int i = 0; i < static_cast<int>(nums.size() - k); ++i) {
            minHeap.pop();
        }
        cout << "initialized" << endl;
    }
    
    int add(int val) {
        minHeap.push(val);
        while (minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};
