class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap(stones.begin(), stones.end());
        while (heap.size() > 1) {
            int stone1 = heap.top(); 
            heap.pop();
            int stone2 = heap.top();
            heap.pop();
            int newStone = stone1 - stone2;
            if (newStone) heap.push(newStone);
        }
        return heap.size() == 0 ? 0 : heap.top();
    }
};
