class Solution {
public:
    int changeUtil (int amount, vector<int>& coins, int index, vector<vector<int>> &dp) {
        if (amount == 0) return 1;
        if (index >= coins.size()) return 0;
        int ans1 = 0, ans2 = 0;
        if (dp[index][amount] != -1) return dp[index][amount];
        if (amount >= coins[index]) {
            ans1 += changeUtil (amount - coins[index], coins, index, dp);
        }
        ans2 = changeUtil (amount, coins, index+1, dp);
        return dp[index][amount] = ans1 + ans2;

    }
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp (coins.size()+10, vector<int>(amount+10, -1));
        return changeUtil (amount, coins, 0 ,dp);
    }
};