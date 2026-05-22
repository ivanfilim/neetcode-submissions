class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int buy_price = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i - 1] < buy_price) {
                buy_price = prices[i - 1];
            }
            result = max(result, prices[i] - buy_price);
        }
        return result;
    }
};