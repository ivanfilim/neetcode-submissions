class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int max = Arrays.stream(piles).max().getAsInt();
        int l = 1, r = max;
        int res = 1;
        main: while (l <= r) {
            int speed = l + (r - l) / 2;
            int time = 0;
            for (int pile: piles) {
                time += pile / speed;
                if (pile % speed > 0)
                    ++time;
                if (time > h) {
                    l = speed + 1;
                    continue main;
                }
            }
            res = speed;
            r = speed - 1;
        }
        return res;
    }
}
