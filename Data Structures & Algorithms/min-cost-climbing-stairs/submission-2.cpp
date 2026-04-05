class Solution {
public:
    int minCostClimbingStairsUtil (int n, vector<int>& cost, vector<int> &dp) {
        if(n < 0 ) return INT_MAX;
        if (n == 0 || n == 1) return cost[n];
        if (dp[n] != -1) return dp[n];
        return dp[n] = cost[n] + min (minCostClimbingStairsUtil(n-1, cost, dp), minCostClimbingStairsUtil(n-2, cost, dp));
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return min(minCostClimbingStairsUtil (cost.size()-1, cost, dp), minCostClimbingStairsUtil (cost.size()-2, cost, dp));
    }
};