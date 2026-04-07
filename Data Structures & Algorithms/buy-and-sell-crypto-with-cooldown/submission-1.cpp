class Solution {
public:
    int maxProfitUtil (vector<int>& prices, int buy, int index, vector<vector<int>> &dp) {
        if (index >= prices.size()) return 0;

        // if buy == 0 -> 2 options. 1. either buy or 2. just skip
        if (dp[index][buy] != -1) return dp[index][buy];
        if (!buy) {
            return dp[index][buy] = max (-prices[index] + maxProfitUtil (prices, 1, index+1, dp), maxProfitUtil (prices, 0, index+1, dp));
        } else {
            return dp[index][buy] = max(prices[index] + maxProfitUtil (prices, 0, index+2, dp), maxProfitUtil (prices, 1, index+1, dp));
        }

    }
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        vector<vector<int>> dp (prices.size(), vector<int>(2, -1));
        return maxProfitUtil (prices, buy,0, dp);
    }
};