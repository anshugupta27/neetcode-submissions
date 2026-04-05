class Solution {
public:
    int robUtil (vector<int>& nums, int index, vector<int>&dp) {
        if (index < 0) return 0;
        if(dp[index] != -1) return dp[index];
        int take = nums[index] + robUtil (nums, index - 2, dp);
        int notTake = robUtil (nums, index - 1, dp);
        return dp[index] = max (take, notTake);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return max(robUtil (nums, nums.size()-1, dp), robUtil (nums, nums.size()-2, dp));
    }
};