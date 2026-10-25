class Solution {
    public int maxProfit(int[] prices) {
        int res = 0;
        int minPrice = prices[0];
        for (int i = 1; i < prices.length; ++i) {
            res = Math.max(res, prices[i] - minPrice);
            minPrice = Math.min(minPrice, prices[i]);
        }
        return res;
    }
}