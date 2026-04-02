class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyDay = prices[0], maxProfit = INT_MIN;
        for (int i = 1 ; i < prices.size() ; i++) {
            maxProfit = max (maxProfit, prices[i] - buyDay);
            buyDay = min (buyDay, prices[i]);
        }
        return maxProfit < 0 ? 0 : maxProfit;
    }
};