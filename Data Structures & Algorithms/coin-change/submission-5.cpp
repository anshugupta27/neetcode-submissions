class Solution {
public:
    int coinChangeUtil (int start, vector<int>& coins, int amount, vector<vector<int>> &dp) {
        if (amount == 0) return 0;
        if (start == coins.size()) return INT_MAX-1;
        if (dp[start][amount] != -1) return dp[start][amount];

        int taken = INT_MAX-1, notTaken = INT_MAX-1;
        if (amount >= coins[start]) {
        // take 
        taken = 1 + coinChangeUtil (start, coins, amount - coins[start], dp);
        }
        // cant take
        notTaken = coinChangeUtil (start + 1, coins, amount, dp);

        return dp[start][amount] = min (taken, notTaken);


    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        int ans = coinChangeUtil (0, coins, amount, dp) ;
        return ans == INT_MAX -1 ? -1 : ans;
    }
};