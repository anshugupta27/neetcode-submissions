class Solution {
public:
    int climbStairsUtil (int n, vector<int> &dp) {
        if (n < 0) return 0;
        if (n == 1 || n == 0) return 1;
        if (dp[n] != -1) return dp[n];
        return dp[n] = climbStairsUtil (n-1, dp) + climbStairsUtil (n-2, dp) ;
    }
    int climbStairs(int n) {
        vector<int> dp (n+1, -1);
        return climbStairsUtil (n, dp);
    }
};