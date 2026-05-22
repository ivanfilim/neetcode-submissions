class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int biggest_pile = *max_element(piles.begin(), piles.end());
        int res = biggest_pile;
        int l = 1;
        int r = biggest_pile;
        while (l <= r) {
            int curr_k = l + (r - l) / 2;
            int time_to_eat = 0;
            for (int pile: piles) {
                time_to_eat += ceil(static_cast<double>(pile) / curr_k);
            }
            if (time_to_eat > h) {
                l = curr_k + 1;
            } else {
                res = curr_k;
                r = curr_k - 1;
            }
        }
        return res;
    }
};
