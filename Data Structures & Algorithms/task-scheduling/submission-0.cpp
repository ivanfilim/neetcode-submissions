class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> heap;
        vector<int> freqs(26);
        for (char c: tasks) {
            ++freqs[c - 'A'];
        }
        for (int freq: freqs) {
            if (freq > 0) heap.push(freq);
        }
        int time = 0;
        queue<pair<int, int>> q;
        while (!heap.empty() || !q.empty()) {
            if (!q.empty() && q.front().second == time) {
                heap.push(q.front().first);
                q.pop();
            }
            if (!heap.empty()) {
                int currTaskFreq = heap.top();
                heap.pop();
                if (currTaskFreq > 1)
                    q.push(pair(currTaskFreq - 1, time + n + 1));
            }
            ++time;
        }
        return time;
    }
};
