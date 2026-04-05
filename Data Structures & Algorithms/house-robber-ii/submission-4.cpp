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
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max (nums[0], nums[1]);
        
        vector<int> dp(nums.size()+1, -1);
        int lastNotTaken = robUtil (nums, nums.size()-2, dp);
        reverse(nums.begin(), nums.end());
        vector<int> dp2(nums.size()+1, -1);
        int firstNotTaken = robUtil (nums, nums.size()-2, dp2);
        return max(lastNotTaken, firstNotTaken);
    }
};