class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        set<int> possible_starts;
        for (int n : s) {
            if (s.find(n - 1) == s.end()) {
                possible_starts.insert(n);
            }
        }
        int result = 0;
        for (int start : possible_starts) {
            int curr_el = start;
            set<int> sequence;
            while (s.find(curr_el) != s.end()) {
                sequence.insert(curr_el);
                ++curr_el;
            }
            if (sequence.size() > result) {
                result = sequence.size();
            }
        }
        return result;
    }
};
