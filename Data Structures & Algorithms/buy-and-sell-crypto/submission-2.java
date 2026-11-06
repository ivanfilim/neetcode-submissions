class Solution {
    public int maxProfit(int[] prices) {
        int res = 0;
        int buyIdx = 0, sellIdx = 1;
        while (sellIdx < prices.length) {
            res = Math.max(res, prices[sellIdx] - prices[buyIdx]);
            if (prices[sellIdx] < prices[buyIdx]) {
                buyIdx = sellIdx;
            }
            ++sellIdx;
        }
        return res;
    }
}
