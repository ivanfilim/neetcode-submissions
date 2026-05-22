class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for (int num: nums) {
            s.insert(num);
        }        
        set<int> ps;
        for (int num: nums) {
            if (s.find(num - 1) == s.end()) {
                ps.insert(num);
            }
        }
        int res = 0;
        for (int num: ps) {
            int curr = num;
            int len = 1;
            while (s.find(curr + 1) != s.end()) {
                ++curr;
                ++len;
            }
            res = max(res, len);
        }
        return res;
    }
};
