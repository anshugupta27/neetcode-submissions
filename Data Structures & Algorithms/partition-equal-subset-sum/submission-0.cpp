class Solution {
public:
    bool canPartitionUtil (int target, int index, vector<int>& nums, vector<vector<int>> &dp) {
        if (target == 0) return true;
        if (index == nums.size()) return false;
        if(dp[index][target] != -1) return dp[index][target];

        bool take = false, notTake = false;
        if (target >= nums[index]) {
            take = canPartitionUtil (target - nums[index], index + 1, nums, dp);
        }
        notTake = canPartitionUtil (target, index + 1, nums, dp);
        return dp[index][target] = take || notTake;

    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int i = 0 ; i < nums.size() ; i++) totalSum += nums[i];
        if (totalSum % 2) return false;
        int targetSum = totalSum/2;
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(nums.size(), vector<int>(targetSum+10, -1));
        return canPartitionUtil (targetSum, 0, nums, dp);
    }
};