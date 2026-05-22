class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        auto pq = priority_queue<int, vector<int>>(
            stones.begin(), stones.end()
        );
        while (pq.size() > 1) {
            int first_heaviest = pq.top();
            pq.pop();
            int second_heaviest = pq.top();
            pq.pop();
            int diff = first_heaviest - second_heaviest;
            if (diff != 0) {
                pq.push(diff);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};
